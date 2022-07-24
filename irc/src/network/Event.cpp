#include "Event.hpp"

Event::Event() {}

Event::Event(const Event& obj) {
    (void)obj;
}

Event::~Event() {}

Event& Event::operator=(const Event& obj) {
    (void)obj;
    return *this;
}

void Event::push(const Message& msg) {
    this->req.push_back(msg);
}

const Message Event::pop() {
    Message msg = this->req.front();
    this->req.pop_front();
    return msg;
}

bool Event::isEmpty() const {
    return this->req.empty();
}