#include "PartService.hpp"

PartService::PartService() : Service() {}

PartService::PartService(Repository* const repository, Event* const event) : Service(repository, event) {}

PartService::PartService(const PartService& obj) : Service(obj) {}

PartService::~PartService() {}

PartService& PartService::operator=(const PartService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> PartService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    if (param.size() == 0) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("PART")));
        return ret;
    }

    std::vector<std::string> channelNames = Util::split(param[0], ',');
    for (std::vector<std::string>::iterator it = channelNames.begin(); it != channelNames.end(); ++it) {
        std::string channelName = *it;
        if (channelName[0] != '#') {
            ret.push_back(Message::create(server, user, StatusCode::ERR_BADCHANMASK(channelName)));
            continue;
        }

        Channel* channel = repository->getChannelByName(channelName);
        if (channel == NULL) {
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOSUCHCHANNEL(channelName)));
            continue;
        }

        if (!repository->isUserInChannel(user, channel)) {
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOTONCHANNEL(channelName)));
            continue;
        }
        std::string userName = user->nickname;
        const std::vector<UserInChannel*> userInChannel = this->repository->getUsersByChannel(channel);
        for (std::vector<UserInChannel*>::const_iterator it = userInChannel.begin(); it != userInChannel.end(); ++it) {
            ret.push_back(Message::create(user, (*it)->user, StatusCode::MSG_PART(channelName, userName)));
        }
        repository->removeUserFromChannel(user, channel);
    }
    return ret;
}
