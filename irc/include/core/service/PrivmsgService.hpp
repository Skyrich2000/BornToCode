#ifndef PRIVMSGSERVICE_HPP
#define PRIVMSGSERVICE_HPP

#include <set>
#include <vector>

#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

#define PRIVMSG 0
#define NOTICE 1

class PrivmsgService : public Service {
   private:
    bool msgType;
    PrivmsgService();
    PrivmsgService& operator=(const PrivmsgService& obj);
    PrivmsgService(const PrivmsgService& obj);

    void sendToChannel(std::vector<Message>& ret, User* user, const std::string channelName, const std::string text);
    void sendToUser(std::vector<Message>& ret, User* user, const std::string nickname, const std::string text);

   public:
    PrivmsgService(Repository* const repository, Event* const event);
    virtual ~PrivmsgService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
    void setIsNotice(bool type);
};

#endif
