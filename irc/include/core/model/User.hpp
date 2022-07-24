#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
   private:
    int fd;

    User();

   public:
    std::string nickname;
    std::string username;
    std::string hostname;
    std::string servername;
    std::string realname;
    int registerStatus;

    User(int fd);
    User(const User& obj);
    ~User();

    User& operator=(const User& obj);
    bool operator==(const User& obj) const;

    int getFd() const;
    bool isRegistered() const;

    static const int REGISTER_PASS = 0x001;
    static const int REGISTER_USER = 0x010;
    static const int REGISTER_NICK = 0x100;
};

#endif