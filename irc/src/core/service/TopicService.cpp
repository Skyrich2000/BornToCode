#include "TopicService.hpp"

TopicService::TopicService() : Service() {}

TopicService::TopicService(Repository* const repository, Event* const event) : Service(repository, event) {}

TopicService::TopicService(const TopicService& obj) : Service(obj) {}

TopicService::~TopicService() {}

TopicService& TopicService::operator=(const TopicService& obj) {
    (void)obj;
    return (*this);
}

/*
4.2.4 Topic message

      Command: TOPIC
   Parameters: <channel> [<topic>]

   The TOPIC message is used to change or view the topic of a channel.
   The topic for channel <channel> is returned if there is no <topic>
   given.  If the <topic> parameter is present, the topic for that
   channel will be changed, if the channel modes permit this action.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
           RPL_NOTOPIC                     RPL_TOPIC
           ERR_CHANOPRIVSNEEDED


   TOPIC								param : 0
   TOPIC #chn							param : 1
   TOPIC #chn change topic message		param : 2 >= x
*/

const std::vector<Message> TopicService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (param.size() == 0) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("TOPIC")));
        return ret;
    }

    std::string channelName = param[0];
    Channel* channel = this->repository->getChannelByName(channelName);
    if (channelName[0] != '#' || channel == NULL) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTONCHANNEL(channelName)));
        return ret;
    }

    std::string topic = channel->getTopic();
    if (param.size() == 1) {
        if (topic == "") {
            ret.push_back(Message::create(server, user, StatusCode::RPL_NOTOPIC(channelName)));
            return ret;
        }
        ret.push_back(Message::create(server, user, StatusCode::RPL_TOPIC(channelName, topic)));
        return ret;
    }

    UserInChannel* userInChannel = this->repository->getUserInChannel(user, channel);
    if (userInChannel == NULL) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTONCHANNEL(channelName)));
        return ret;
    }

    if (channel->isMode('t') && !userInChannel->is_operator) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_CHANOPRIVSNEEDED(channelName)));
        return ret;
    }

    topic = param[1];
    channel->setTopic(topic);
    ret.push_back(Message::create(server, user, StatusCode::RPL_TOPIC(channelName, topic)));
    return ret;
}
