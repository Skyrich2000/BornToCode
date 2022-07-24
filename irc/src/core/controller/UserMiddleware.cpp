#include "UserMiddleware.hpp"

UserMiddleware::UserMiddleware() : repository(NULL) {}

UserMiddleware::UserMiddleware(Repository* const repository) : repository(repository) {}

UserMiddleware::UserMiddleware(const UserMiddleware& obj) : repository(obj.repository) {}

UserMiddleware::~UserMiddleware() {}

UserMiddleware& UserMiddleware::operator=(const UserMiddleware& obj) {
    (void)obj;
    return (*this);
}

User* UserMiddleware::getUser(int fd) {
    User* user = repository->getUser(fd);

    if (user == NULL) {
        user = repository->addUser(fd);

        if (this->repository->getPassword() == "")
            user->registerStatus |= User::REGISTER_PASS;
    }

    return user;
}