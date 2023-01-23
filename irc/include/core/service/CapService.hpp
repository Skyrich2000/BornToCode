#ifndef CAPSERVICE_HPP
#define CAPSERVICE_HPP

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class CapService : public Service {
   private:
    CapService();
    CapService& operator=(const CapService& obj);
    CapService(const CapService& obj);

   public:
    CapService(Repository* const repository, Event* const event);
    virtual ~CapService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
