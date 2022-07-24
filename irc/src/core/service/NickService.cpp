#include "NickService.hpp"

NickService::NickService() : Service() {}

NickService::NickService(Repository* const repository, Event* const event) : Service(repository, event) {}

NickService::NickService(const NickService& obj) : Service(obj) {}

NickService::~NickService() {}

NickService& NickService::operator=(const NickService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> NickService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (param.size() == 0) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NONICKNAMEGIVEN()));
        return ret;
    }

    std::string nickname = param.front();
    if (!isNickname(nickname)) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_ERRONEUSNICKNAME(nickname)));
        return ret;
    }

    if (this->repository->getUserByNickname(nickname) != NULL) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NICKNAMEINUSE(nickname)));
        user->nickname = nickname;
        return ret;
    }

    std::set<User*> users;
    User oldUser = *user;
    user->nickname = nickname;
    user->registerStatus |= User::REGISTER_NICK;

    std::vector<Channel*> _channels = this->repository->getChannelsByUser(user);
    for (std::vector<Channel*>::iterator cit = _channels.begin(); cit != _channels.end(); ++cit) {
        std::vector<UserInChannel*> _users = this->repository->getUsersByChannel(*cit);
        for (std::vector<UserInChannel*>::iterator uit = _users.begin(); uit != _users.end(); ++uit) {
            if ((*uit)->user != user) {
                users.insert((*uit)->user);
            }
        }
    };

    for (std::set<User*>::iterator uit = users.begin(); uit != users.end(); ++uit) {
        ret.push_back(Message::create(&oldUser, *uit, StatusCode::MSG_NICK(nickname, false)));
    }

    int is_new_registered = user->isRegistered() && oldUser.registerStatus != user->registerStatus;
    ret.push_back(Message::create(&oldUser, user, StatusCode::MSG_NICK(nickname, is_new_registered)));
    return ret;
}

bool isNickname(const std::string& nick) {
    if (nick.size() > 9)
        return false;
    if (!std::isalpha(nick[0]))
        return false;
    for (size_t i = 1; i < nick.size(); i++) {
        if (std::isalnum(nick[i]))
            continue;
        if (std::strchr(SPECIAL, nick[i]))
            continue;
        return false;
    }
    return true;
}
