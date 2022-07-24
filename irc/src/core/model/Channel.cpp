#include "Channel.hpp"

Channel::Channel() : name(""), topic(""), mode("") {}

Channel::Channel(const std::string& name) : name(name), topic(""), mode("") {}

Channel::Channel(const Channel& obj) {
    *this = obj;
}

Channel::~Channel() {}

Channel& Channel::operator=(const Channel& obj) {
    this->name = obj.name;
    this->topic = obj.topic;
    this->mode = obj.mode;
    return (*this);
}

bool Channel::operator==(const Channel& obj) const {
    return name == obj.name;
}

const std::string& Channel::getName() const {
    return name;
}

const std::string& Channel::getTopic() const {
    return topic;
}

const std::string& Channel::getMode() const {
    return mode;
}

bool Channel::isMode(char mode) const {
    return this->mode.find(mode) != std::string::npos;
}

void Channel::setTopic(const std::string& str) {
    this->topic = str;
}

void Channel::addMode(char mode) {
    if (!isMode(mode))
        this->mode += mode;
}

void Channel::removeMode(char mode) {
    if (isMode(mode))
        this->mode.erase(this->mode.find(mode), 1);
}