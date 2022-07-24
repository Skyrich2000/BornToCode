#include "Service.hpp"

Service::Service() : repository(NULL), event(NULL), server(NULL) {}

Service::Service(Repository* const repository, Event* const event) : repository(repository), event(event) {
    this->server = this->repository->getUser(0);
}

Service::Service(const Service& obj) : repository(obj.repository), event(obj.event), server(obj.server) {}

Service::~Service() {}

Service& Service::operator=(const Service& obj) {
    (void)obj;
    return (*this);
}