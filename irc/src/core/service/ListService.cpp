#include "ListService.hpp"

ListService::ListService() : Service() {}

ListService::ListService(Repository* const repository, Event* const event) : Service(repository, event) {}

ListService::ListService(const ListService& obj) : Service(obj) {}

ListService::~ListService() {}

ListService& ListService::operator=(const ListService& obj) {
    (void)obj;
    return (*this);
}

typedef std::vector<Channel*>::const_iterator ChannelIter;
const std::vector<Message> ListService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    std::vector<UserInChannel*> userByCh;
    if (param.size() != 0) {
        for (unsigned int i = 0; i < param.size(); i++) {
            const Channel* channels = repository->getChannelByName(param[i]);
            if (channels == NULL) {
                ret.push_back(Message::create(server, user, StatusCode::RPL_LISTEND()));
                break;
            }
            userByCh = this->repository->getUsersByChannel(channels);
            ret.push_back(Message::create(server, user, StatusCode::RPL_LIST(param[i], userByCh.size(), channels->getTopic())));
            ret.push_back(Message::create(server, user, StatusCode::RPL_LISTEND()));
        }
    } else {
        const std::vector<Channel*> channels = this->repository->getAllChannels();
        ChannelIter channelIter;
        for (channelIter = channels.begin(); channelIter != channels.end(); channelIter++) {
            userByCh = this->repository->getUsersByChannel(*channelIter);
            ret.push_back(Message::create(server, user, StatusCode::RPL_LIST((*channelIter)->getName(), userByCh.size(), (*channelIter)->getTopic())));
        }
        ret.push_back(Message::create(server, user, StatusCode::RPL_LISTEND()));
    }
    return ret;
}
