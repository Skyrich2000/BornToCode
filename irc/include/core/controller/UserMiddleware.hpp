#ifndef USERMIDDLEWARE_HPP
#define USERMIDDLEWARE_HPP

#include "Repository.hpp"

class UserMiddleware {
   private:
    Repository* const repository;

    UserMiddleware();
    UserMiddleware& operator=(const UserMiddleware& obj);
    UserMiddleware(const UserMiddleware& obj);

   public:
    UserMiddleware(Repository* const repository);
    ~UserMiddleware();

    User* getUser(int fd);
};

#endif