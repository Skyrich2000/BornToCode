#include "JoinService.hpp"

JoinService::JoinService() : Service() {}

JoinService::JoinService(Repository* const repository, Event* const event) : Service(repository, event) {}

JoinService::JoinService(const JoinService& obj) : Service(obj) {}

JoinService::~JoinService() {}

JoinService& JoinService::operator=(const JoinService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> JoinService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    if (param.size() == 0) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("JOIN")));
        return ret;
    }

    std::vector<std::string> channelNames = Util::split(param[0], ',');
    for (std::vector<std::string>::iterator it = channelNames.begin(); it != channelNames.end(); ++it) {
        std::string channelName = *it;
        if (channelName[0] != '#') {
            ret.push_back(Message::create(server, user, StatusCode::ERR_BADCHANMASK(channelName)));
            continue;
        }

        Channel* channel = this->repository->getChannelByName(channelName);
        if (channel == NULL) {
            channel = this->repository->addChannel(channelName);
        }

        if (!this->repository->isUserInChannel(user, channel)) {
            this->repository->addUserToChannel(user, channel);
        }

        /*
           If a JOIN is successful, the user is then sent the channel's topic
           (using RPL_TOPIC) and the list of users who are on the channel (using
           RPL_NAMREPLY), which must include the user joining.
         */
        std::string topic = channel->getTopic();
        std::vector<std::string> nicks;
        std::vector<UserInChannel*> _users = this->repository->getUsersByChannel(channel);
        for (std::vector<UserInChannel*>::iterator uit = _users.begin(); uit != _users.end(); ++uit) {
            User* u = (*uit)->user;
            nicks.push_back(u->nickname);
            ret.push_back(Message::create(user, u, StatusCode::MSG_JOIN(channelName)));
        }
        event->push(Message::create(user->getFd(), "TOPIC " + channelName));
        event->push(Message::create(user->getFd(), "NAMES " + channelName));
    }
    return ret;
}
