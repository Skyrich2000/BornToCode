#include "UserService.hpp"

UserService::UserService() : Service() {}

UserService::UserService(Repository* const repository, Event* const event) : Service(repository, event) {}

UserService::UserService(const UserService& obj) : Service(obj) {}

UserService::~UserService() {}

UserService& UserService::operator=(const UserService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> UserService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (param.size() < 4) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("USER")));
        return ret;
    }

    if (user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_ALREADYREGISTRED()));
        return ret;
    }

    std::string username = param[0];
    std::string hostname = param[1];
    std::string servername = param[2];
    std::string realname = param[3];

    user->username = username;
    user->hostname = "ft.irc";
    user->servername = "FT_IRC";
    user->realname = realname;
    user->registerStatus |= User::REGISTER_USER;
    ret.push_back(Message::create(server, user, StatusCode::MSG_USER(user->isRegistered())));
    return ret;
}
