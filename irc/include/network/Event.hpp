#ifndef EVENT_HPP
#define EVENT_HPP

#include <deque>

#include "Message.hpp"

class Event {
   private:
    std::deque<Message> req;

    Event(const Event& obj);

    Event& operator=(const Event& obj);

   public:
    Event();
    ~Event();

    void push(const Message& msg);
    const Message pop();
    bool isEmpty() const;
};

#endif
