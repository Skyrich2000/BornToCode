#ifndef PARTSERVICE_HPP
#define PARTSERVICE_HPP

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class PartService : public Service {
   private:
    PartService();
    PartService& operator=(const PartService& obj);
    PartService(const PartService& obj);

   public:
    PartService(Repository* const repository, Event* const event);
    virtual ~PartService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
