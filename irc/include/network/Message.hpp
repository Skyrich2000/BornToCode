#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "StatusCode.hpp"
#include "User.hpp"
#include "Util.hpp"

class Message {
   private:
    Message();

    Message &operator=(const Message &obj);

   public:
    const int fd;
    const std::string command;
    const std::string targetName;
    const std::vector<std::string> param;

    const std::string nickname;
    const std::string username;
    const std::string hostname;

    const bool isQuit;

    Message(int fd, const std::string &command, const std::string &targetName, const std::vector<std::string> &param, const std::string &nickname, const std::string &username, const std::string &hostname, const bool isQuit = false);
    Message(const Message &obj);
    ~Message();

    const std::string toRawString() const;

    static const Message create(int fd, const std::string &rawstring);
    static const Message create(User *from, User *to, const StatusCode &statusCode);
};

std::ostream &operator<<(std::ostream &os, const Message &Message);

#endif