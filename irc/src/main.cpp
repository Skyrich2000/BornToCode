#include <iostream>
#include <string>

#include "Controller.hpp"
#include "Event.hpp"
#include "JoinService.hpp"
#include "ListService.hpp"
#include "Message.hpp"
#include "ModeService.hpp"
#include "NamesService.hpp"
#include "Network.hpp"
#include "NickService.hpp"
#include "PartService.hpp"
#include "PassService.hpp"
#include "PrivmsgService.hpp"
#include "Repository.hpp"
#include "Service.hpp"
#include "TopicService.hpp"
#include "UserMiddleware.hpp"
#include "UserService.hpp"

#define MAX_PORT 65535

static bool isNumberString(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (std::isdigit(*it) == 0)
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    Repository repository;
    Event event;

    switch (argc) {
        case 3:
            repository.setPassword(argv[2]);
            break;
        case 2:
            break;
        default: {
            std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
            return 1;
        }
    }

    if (!isNumberString(argv[1])) {
        std::cout << "Wrong Port" << std::endl;
        return 1;
    }
    int port = std::stoi(argv[1]);
    if (!(1 <= port && port <= MAX_PORT)) {
        std::cout << "Wrong Port" << std::endl;
        return 1;
    }

    // fd 0 user is server
    User* user = repository.addUser(0);
    user->nickname = "FT_IRC";
    user->username = "FT_IRC";
    user->hostname = "ft.irc";

    UserMiddleware userMiddleware(&repository);

    QuitService quitService(&repository, &event);
    NickService nickService(&repository, &event);
    PassService passService(&repository, &event);
    UserService userService(&repository, &event);
    JoinService joinService(&repository, &event);
    TopicService topicService(&repository, &event);
    ListService listService(&repository, &event);
    NamesService namesService(&repository, &event);
    PartService partService(&repository, &event);
    PrivmsgService privmsgService(&repository, &event);
    PrivmsgService noticeService(&repository, &event);
    ModeService modeService(&repository, &event);

    privmsgService.setIsNotice(PRIVMSG);
    noticeService.setIsNotice(NOTICE);

    Controller controller(&userMiddleware);

    controller.addService("NICK", &nickService);
    controller.addService("QUIT", &quitService);
    controller.addService("PASS", &passService);
    controller.addService("USER", &userService);
    controller.addService("JOIN", &joinService);
    controller.addService("TOPIC", &topicService);
    controller.addService("LIST", &listService);
    controller.addService("NAMES", &namesService);
    controller.addService("PART", &partService);
    controller.addService("PRIVMSG", &privmsgService);
    controller.addService("NOTICE", &noticeService);
    controller.addService("MODE", &modeService);

    try {
        Network network(port, &controller, &event);

        network.run();
    } catch (const std::exception& e) {
        std::cerr << "Network error!" << e.what() << '\n';
    }

    return 0;
}
