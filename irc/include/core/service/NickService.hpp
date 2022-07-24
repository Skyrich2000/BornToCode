#ifndef NICKSERVICE_HPP
#define NICKSERVICE_HPP

#include <ctype.h>

#include <set>

#include "Repository.hpp"
#include "Service.hpp"

#define SPECIAL "[]\\`_^{|}-"

class NickService : public Service {
   private:
    NickService();
    NickService& operator=(const NickService& obj);
    NickService(const NickService& obj);

   public:
    NickService(Repository* const repository, Event* const event);
    virtual ~NickService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

bool isNickname(const std::string& nick);

#endif
