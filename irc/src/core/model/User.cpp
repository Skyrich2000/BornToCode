#include "User.hpp"

User::User() : nickname(""), registerStatus(0) {}

User::User(int fd) : fd(fd), registerStatus(0) {}

User::User(const User& obj) {
    *this = obj;
}

User::~User() {}

User& User::operator=(const User& obj) {
    this->fd = obj.fd;
    this->nickname = obj.nickname;
    this->username = obj.username;
    this->hostname = obj.hostname;
    this->servername = obj.servername;
    this->realname = obj.realname;
    this->registerStatus = obj.registerStatus;
    return (*this);
}

bool User::operator==(const User& obj) const {
    return registerStatus & User::REGISTER_NICK && nickname == obj.nickname;
}

int User::getFd() const {
    return fd;
}

bool User::isRegistered() const {
    return registerStatus == (User::REGISTER_PASS | User::REGISTER_NICK | User::REGISTER_USER);
}