
#ifndef STATUSCODE_HPP
#define STATUSCODE_HPP

#include <algorithm>
#include <string>
#include <vector>

class StatusCode {
   private:
    StatusCode();
    StatusCode(const std::string& code, const std::string& message, const std::string& targetName = "");

    StatusCode& operator=(const StatusCode& obj);

   public:
    const std::string code;
    const std::string targetName;
    const std::string message;

    StatusCode(const StatusCode& obj);
    ~StatusCode();

    static const StatusCode MSG_PASS(int is_registered);
    static const StatusCode MSG_NICK(std::string nick, int is_new_registered);
    static const StatusCode MSG_USER(int is_registered);
    static const StatusCode MSG_QUIT(std::string msg);
    static const StatusCode MSG_JOIN(std::string channel);
    static const StatusCode MSG_PART(std::string channelName, std::string username);
    static const StatusCode MSG_PRIVMSG(std::string target, std::string text);
    static const StatusCode MSG_NOTICE(std::string target, std::string text);

    static const StatusCode RPL_TOPIC(std::string channel, std::string topic);
    static const StatusCode RPL_NOTOPIC(std::string channel);

    static const StatusCode RPL_NAMREPLY(std::string channel, std::vector<std::string> nicks);
    static const StatusCode RPL_ENDOFNAMES(std::string channel);

    static const StatusCode RPL_LIST(std::string channel, int userNum, std::string topic);
    static const StatusCode RPL_LISTEND();

    static const StatusCode RPL_CHANNELMODEIS(std::string channel, std::string mode, std::string param = "");
    static const StatusCode RPL_UMODEIS(std::string mode);

    static const StatusCode ERR_UNKNOWNCOMMAND(std::string command);
    static const StatusCode ERR_NEEDMOREPARAMS(std::string command);
    static const StatusCode ERR_ALREADYREGISTRED();
    static const StatusCode ERR_PASSWDMISMATCH();

    static const StatusCode ERR_NONICKNAMEGIVEN();
    static const StatusCode ERR_NICKNAMEINUSE(std::string nickname);
    static const StatusCode ERR_ERRONEUSNICKNAME(std::string nickname);
    static const StatusCode ERR_BADCHANMASK(std::string channel);
    static const StatusCode ERR_NOTREGISTERED();

    static const StatusCode ERR_NOSUCHCHANNEL(std::string channel);
    static const StatusCode ERR_NOTONCHANNEL(std::string channel);

    static const StatusCode ERR_NORECIPIENT(std::string command);
    static const StatusCode ERR_NOTEXTTOSEND();
    static const StatusCode ERR_TOOMANYTARGETS(std::string target);
    static const StatusCode ERR_CANNOTSENDTOCHAN(std::string channel);
    static const StatusCode ERR_NOSUCHNICK(std::string nickname);

    static const StatusCode ERR_CHANOPRIVSNEEDED(std::string channel);
    static const StatusCode ERR_UNKNOWNMODE(std::string mode);
    static const StatusCode ERR_USERSDONTMATCH();
    static const StatusCode ERR_UMODEUNKNOWNFLAG();
};

#endif
