#ifndef LISTSERVICE_HPP
#define LISTSERVICE_HPP

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class ListService : public Service {
   private:
    ListService();
    ListService& operator=(const ListService& obj);
    ListService(const ListService& obj);

   public:
    ListService(Repository* const repository, Event* const event);
    virtual ~ListService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
