#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <map>
#include <vector>

#include "Channel.hpp"
#include "User.hpp"

#define SUCCESS 1
#define FAIL 0

struct UserInChannel {
    bool is_host;
    bool is_operator;
    User* user;
};

class Repository {
   private:
    std::string password;
    std::map<int, User> users;
    std::map<std::string, Channel> channels;
    std::vector<std::pair<UserInChannel, Channel*> > user_channel;

    Repository(const Repository& obj);
    Repository& operator=(const Repository& obj);

   public:
    typedef std::map<int, User>::iterator UsersIter;
    typedef std::map<std::string, Channel>::iterator ChannelsIter;
    typedef std::vector<std::pair<UserInChannel, Channel*> >::iterator UserChannelIter;
    typedef std::vector<std::pair<UserInChannel, Channel*> >::const_iterator UserChannelConstIter;

    Repository();
    ~Repository();

    std::string getPassword() const;
    void setPassword(const std::string& password);

    const std::vector<User*> getAllUsers();
    User* getUserByNickname(const std::string& nickname);
    User* getUser(int fd);
    User* addUser(int fd);
    void removeUser(int fd);

    const std::vector<Channel*> getAllChannels();
    Channel* getChannelByName(const std::string& name);
    Channel* addChannel(std::string name);
    void removeChannel(std::string name);

    const std::vector<UserInChannel*> getUsersByChannel(const Channel* const channel);
    const std::vector<Channel*> getChannelsByUser(const User* const user) const;
    UserInChannel* getUserInChannel(const User* const user, const Channel* const channel);
    bool isUserInChannel(const User* const user, const Channel* const channel) const;
    void addUserToChannel(User* const user, Channel* const channel);
    void removeUserFromChannel(const User* const user, const Channel* const channel);
};

#endif