#include "QuitService.hpp"

QuitService::QuitService() : Service() {}

QuitService::QuitService(Repository* const repository, Event* const event) : Service(repository, event) {}

QuitService::QuitService(const QuitService& obj) : Service(obj) {}

QuitService::~QuitService() {}

QuitService& QuitService::operator=(const QuitService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> QuitService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    std::string msg = param.size() > 0 ? param[0] : "";

    std::vector<Channel*> channels = this->repository->getChannelsByUser(user);
    for (std::vector<Channel*>::iterator cit = channels.begin(); cit != channels.end(); ++cit) {
        Channel* channel = *cit;
        this->repository->removeUserFromChannel(user, channel);

        std::vector<UserInChannel*> users = this->repository->getUsersByChannel(channel);
        for (std::vector<UserInChannel*>::iterator uit = users.begin(); uit != users.end(); ++uit) {
            ret.push_back(Message::create(user, (*uit)->user, StatusCode::MSG_QUIT(msg)));
        }
    }
    ret.push_back(Message::create(user, user, StatusCode::MSG_QUIT(msg)));

    this->repository->removeUser(user->getFd());

    return ret;
}
