#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "Event.hpp"
#include "Message.hpp"
#include "Repository.hpp"
#include "StatusCode.hpp"

class Service {
   private:
    Service& operator=(const Service& obj);

   protected:
    Repository* const repository;
    Event* const event;
    User* server;

    Service();
    Service(const Service& obj);

   public:
    Service(Repository* const repository, Event* const event);
    virtual ~Service();

    virtual const std::vector<Message> execute(User* user, const std::vector<std::string>& param) = 0;
};

#endif
