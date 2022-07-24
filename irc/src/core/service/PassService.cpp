#include "PassService.hpp"

PassService::PassService() : Service() {}

PassService::PassService(Repository* const repository, Event* const event) : Service(repository, event) {}

PassService::PassService(const PassService& obj) : Service(obj) {}

PassService::~PassService() {}

PassService& PassService::operator=(const PassService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> PassService::execute(User* user, const std::vector<std::string>& param) {
    std::vector<Message> ret;

    if (param.size() < 1) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("PASS")));
        return ret;
    }

    if (user->isRegistered()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_ALREADYREGISTRED()));
        return ret;
    }

    std::string password = param.front();
    if (password != this->repository->getPassword()) {
        ret.push_back(Message::create(server, user, StatusCode::ERR_PASSWDMISMATCH()));
        return ret;
    }

    user->registerStatus |= User::REGISTER_PASS;
    ret.push_back(Message::create(server, user, StatusCode::MSG_PASS(user->isRegistered())));
    return ret;
}
