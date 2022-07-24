#ifndef USERSERVICE_HPP
#define USERSERVICE_HPP

#include "Repository.hpp"
#include "Service.hpp"

class UserService : public Service {
   private:
    UserService();
    UserService& operator=(const UserService& obj);
    UserService(const UserService& obj);

   public:
    UserService(Repository* const repository, Event* const event);
    virtual ~UserService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
