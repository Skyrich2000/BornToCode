#ifndef NAMESSERVICE_HPP
#define NAMESSERVICE_HPP

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class NamesService : public Service {
   private:
    NamesService();
    NamesService& operator=(const NamesService& obj);
    NamesService(const NamesService& obj);

   public:
    NamesService(Repository* const repository, Event* const event);
    virtual ~NamesService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
    void printNames(const Channel* const channel, std::vector<Message>& ret, const std::string& channelName, User* user);
};

#endif
