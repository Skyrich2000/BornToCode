#include "NamesService.hpp"

NamesService::NamesService() : Service() {}

NamesService::NamesService(Repository* const repository, Event* const event) : Service(repository, event) {}

NamesService::NamesService(const NamesService& obj) : Service(obj) {}

NamesService::~NamesService() {}

NamesService& NamesService::operator=(const NamesService& obj) {
    (void)obj;
    return (*this);
}

void NamesService::printNames(const Channel* const channel, std::vector<Message>& ret,
                              const std::string& channelName, User* user) {
    std::vector<UserInChannel*> users;
    std::vector<std::string> nicks;

    users = repository->getUsersByChannel(channel);
    typedef std::vector<UserInChannel*>::const_iterator UserIter;
    for (UserIter userIter = users.begin(); userIter != users.end(); userIter++) {
        if ((*userIter)->is_host == true)
            nicks.push_back("@" + (*userIter)->user->nickname);
        else
            nicks.push_back((*userIter)->user->nickname);
    }
    ret.push_back(Message::create(server, user, StatusCode::RPL_NAMREPLY(channelName, nicks)));
    ret.push_back(Message::create(server, user, StatusCode::RPL_ENDOFNAMES(channelName)));
}

const std::vector<Message> NamesService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    std::string channelName;
    if (param.size() != 0) {
        for (unsigned int i = 0; i < param.size(); i++) {
            channelName = param[i];
            Channel* channel = repository->getChannelByName(channelName);
            if (channel == NULL) {
                ret.push_back(Message::create(server, user, StatusCode::RPL_ENDOFNAMES(channelName)));
                break;
            }
            printNames(channel, ret, channelName, user);
        }
    } else {
        typedef std::vector<Channel*>::const_iterator ChannelIter;
        const std::vector<Channel*> channels = this->repository->getAllChannels();
        ChannelIter channelIter;
        for (channelIter = channels.begin(); channelIter != channels.end(); channelIter++) {
            channelName = (*channelIter)->getName();
            printNames(*channelIter, ret, channelName, user);
        }
    }
    return ret;
}
