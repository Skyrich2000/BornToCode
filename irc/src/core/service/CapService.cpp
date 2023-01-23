#include "CapService.hpp"

CapService::CapService() : Service() {}

CapService::CapService(Repository* const repository, Event* const event) : Service(repository, event) {}

CapService::CapService(const CapService& obj) : Service(obj) {}

CapService::~CapService() {}

CapService& CapService::operator=(const CapService& obj) {
    (void)obj;
    return (*this);
}

/**
 * this command is only for IRSSI client
 */
const std::vector<Message> CapService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (param.size() == 0) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("CAP")));
        return ret;
    }

    if (param.front() == "LS")
        ret.push_back(Message::create(server, user, StatusCode::MSG_CAP()));

    return ret;
}
