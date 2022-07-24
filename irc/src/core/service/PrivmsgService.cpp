#include "PrivmsgService.hpp"

PrivmsgService::PrivmsgService() : Service() {}

PrivmsgService::PrivmsgService(Repository* const repository, Event* const event) : Service(repository, event) {}

PrivmsgService::PrivmsgService(const PrivmsgService& obj) : Service(obj) {}

PrivmsgService::~PrivmsgService() {}

PrivmsgService& PrivmsgService::operator=(const PrivmsgService& obj) {
    (void)obj;
    return (*this);
}

void PrivmsgService::setIsNotice(bool type) {
    if (type == NOTICE)
        msgType = NOTICE;
    msgType = PRIVMSG;
}

void PrivmsgService::sendToChannel(std::vector<Message>& ret, User* user, const std::string channelName, const std::string text) {
    Channel* channel = repository->getChannelByName(channelName);
    if (channel == NULL) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOSUCHCHANNEL(channelName)));
        return;
    }

    if (channel->isMode('n') && !repository->isUserInChannel(user, channel)) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_CANNOTSENDTOCHAN(channelName)));
        return;
    }

    std::vector<UserInChannel*> users = this->repository->getUsersByChannel(channel);
    for (std::vector<UserInChannel*>::iterator it = users.begin(); it != users.end(); ++it) {
        User* targetUser = (*it)->user;
        if (targetUser != user) {
            if (msgType == PRIVMSG)
                ret.push_back(Message::create(user, targetUser, StatusCode::MSG_PRIVMSG(channelName, text)));
            else
                ret.push_back(Message::create(user, targetUser, StatusCode::MSG_NOTICE(channelName, text)));
        }
    }
}

void PrivmsgService::sendToUser(std::vector<Message>& ret, User* user, const std::string nickname, const std::string text) {
    User* targetUser = repository->getUserByNickname(nickname);
    if (targetUser == NULL) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOSUCHNICK(nickname)));
        return;
    }
    if (msgType == PRIVMSG)
        ret.push_back(Message::create(user, targetUser, StatusCode::MSG_PRIVMSG(nickname, text)));
    else
        ret.push_back(Message::create(user, targetUser, StatusCode::MSG_NOTICE(nickname, text)));
}

const std::vector<Message> PrivmsgService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    if (param.size() == 0) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_NORECIPIENT("PRIVMSG")));
        return ret;
    }

    if (param.size() == 1) {
        if (msgType == PRIVMSG)
            ret.push_back(Message::create(server, user, StatusCode::ERR_NOTEXTTOSEND()));
        return ret;
    }

    std::vector<std::string> targets = Util::split(param[0], ',');
    std::string text = param[1];
    std::set<std::string> recipients;

    for (std::vector<std::string>::iterator it = targets.begin(); it != targets.end(); ++it) {
        std::string target = *it;
        if (recipients.find(target) != recipients.end()) {
            if (msgType == PRIVMSG)
                ret.push_back(Message::create(server, user, StatusCode::ERR_TOOMANYTARGETS(target)));
            continue;
        }

        if (target[0] == '#') {
            this->sendToChannel(ret, user, target, text);
        } else {
            this->sendToUser(ret, user, target, text);
        }
        recipients.insert(target);
    }

    return ret;
}
