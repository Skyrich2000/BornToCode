#include "Controller.hpp"

Controller::Controller() : userMiddleware(NULL) {}

Controller::Controller(UserMiddleware* const userMiddleware) : userMiddleware(userMiddleware) {}

Controller::Controller(const Controller& obj) : userMiddleware(obj.userMiddleware) {}

Controller::~Controller() {}

Controller& Controller::operator=(const Controller& obj) {
    (void)obj;
    return (*this);
}

void Controller::addService(const std::string& command, Service* const service) {
    this->services.insert(std::pair<std::string, Service* const>(command, service));
}

const std::vector<Message> Controller::execute(const Message& req) const {
    User* user = this->userMiddleware->getUser(req.fd);
    User* server = this->userMiddleware->getUser(0);

    std::map<std::string, Service* const>::const_iterator it = this->services.find(req.command);
    if (it == this->services.end()) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_UNKNOWNCOMMAND(req.command)));
    }

    return it->second->execute(user, req.param);
}
