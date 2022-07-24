#include "Repository.hpp"

Repository::Repository() : password("") {}

Repository::Repository(const Repository& obj) {
    (void)obj;
}

Repository::~Repository() {}

Repository& Repository::operator=(const Repository& obj) {
    (void)obj;
    return (*this);
}

std::string Repository::getPassword() const {
    return password;
}

void Repository::setPassword(const std::string& password) {
    this->password = password;
}

const std::vector<User*> Repository::getAllUsers() {
    std::vector<User*> ret;

    for (UsersIter uit = users.begin(); uit != users.end(); ++uit) {
        ret.push_back(&uit->second);
    }
    return ret;
}

User* Repository::getUserByNickname(const std::string& nickname) {
    for (UsersIter uit = users.begin(); uit != users.end(); ++uit)
        if (uit->second.registerStatus & User::REGISTER_NICK && uit->second.nickname == nickname)
            return &uit->second;
    return NULL;
}

User* Repository::getUser(int fd) {
    UsersIter it = users.find(fd);
    if (it == users.end())
        return NULL;
    return &it->second;
}

// check if insert failed
User* Repository::addUser(int fd) {
    UsersIter itr = users.insert(std::pair<int, User>(fd, User(fd))).first;
    return &itr->second;
}

void Repository::removeUser(int fd) {
    users.erase(fd);
}

const std::vector<Channel*> Repository::getAllChannels() {
    std::vector<Channel*> ret;
    for (ChannelsIter it = channels.begin(); it != channels.end(); ++it)
        ret.push_back(&it->second);
    return ret;
}

Channel* Repository::getChannelByName(const std::string& name) {
    ChannelsIter it = channels.find(name);
    if (it == channels.end())
        return NULL;
    return &it->second;
}

Channel* Repository::addChannel(std::string name) {
    ChannelsIter itr = channels.insert(std::pair<std::string, Channel>(name, Channel(name))).first;
    return &itr->second;
}

void Repository::removeChannel(std::string name) {
    channels.erase(name);
}

const std::vector<UserInChannel*> Repository::getUsersByChannel(const Channel* const channel) {
    std::vector<UserInChannel*> ret;
    for (UserChannelIter it = user_channel.begin(); it != user_channel.end(); ++it)
        if (*it->second == *channel)
            ret.push_back(&it->first);
    return ret;
}

const std::vector<Channel*> Repository::getChannelsByUser(const User* const user) const {
    std::vector<Channel*> ret;
    for (UserChannelConstIter it = user_channel.begin(); it != user_channel.end(); ++it)
        if (it->first.user == user)
            ret.push_back(it->second);
    return ret;
}

UserInChannel* Repository::getUserInChannel(const User* const user, const Channel* const channel) {
    for (UserChannelIter it = user_channel.begin(); it != user_channel.end(); ++it)
        if (*it->first.user == *user && *it->second == *channel)
            return &it->first;
    return NULL;
}

bool Repository::isUserInChannel(const User* const user, const Channel* const channel) const {
    for (UserChannelConstIter it = user_channel.begin(); it != user_channel.end(); ++it)
        if (*it->first.user == *user && *it->second == *channel)
            return true;
    return false;
}

void Repository::addUserToChannel(User* const user, Channel* const channel) {
    UserInChannel userStruct;
    if (getUsersByChannel(channel).size() == 0) {
        userStruct.is_host = true;
        userStruct.is_operator = true;
    } else {
        userStruct.is_host = false;
        userStruct.is_operator = false;
    }
    userStruct.user = user;
    user_channel.push_back(std::pair<UserInChannel, Channel* const>(userStruct, channel));
}

void Repository::removeUserFromChannel(const User* const user, const Channel* const channel) {
    for (UserChannelIter it = user_channel.begin(); it != user_channel.end(); ++it) {
        if (*it->first.user == *user && *it->second == *channel) {
            user_channel.erase(it);
            return;
        }
    }
}
