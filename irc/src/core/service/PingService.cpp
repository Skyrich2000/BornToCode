#include "PingService.hpp"

PingService::PingService() : Service() {}

PingService::PingService(Repository* const repository, Event* const event) : Service(repository, event) {}

PingService::PingService(const PingService& obj) : Service(obj) {}

PingService::~PingService() {}

PingService& PingService::operator=(const PingService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> PingService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (!user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
        return ret;
    }

    if (param.size() < 1) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("PING")));
        return ret;
    }

    ret.push_back(Message::create(server, user, StatusCode::MSG_PONG(param.front())));

    return ret;
}
