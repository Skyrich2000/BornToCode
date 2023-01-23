#ifndef PINGSERVICE_HPP
#define PINGSERVICE_HPP

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class PingService : public Service {
   private:
    PingService();
    PingService& operator=(const PingService& obj);
    PingService(const PingService& obj);

   public:
    PingService(Repository* const repository, Event* const event);
    virtual ~PingService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
