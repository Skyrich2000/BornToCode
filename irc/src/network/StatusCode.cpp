#include "StatusCode.hpp"

#include <sstream>

StatusCode::StatusCode() : code(0), targetName(""), message("") {}

StatusCode::StatusCode(const std::string& code, const std::string& message, const std::string& targetName) : code(code), targetName(targetName), message(message) {}

StatusCode::StatusCode(const StatusCode& obj) : code(obj.code), message(obj.message) {}

StatusCode::~StatusCode() {}

StatusCode& StatusCode::operator=(const StatusCode& obj) {
    (void)obj;
    return (*this);
}

const StatusCode StatusCode::MSG_PASS(int is_registered) {
    return StatusCode("PASS", " :Password accepted" + std::string(is_registered ? " (new registered!)" : ""));
}

const StatusCode StatusCode::MSG_NICK(std::string nick, int is_new_registered) {
    (void)is_new_registered;
    return StatusCode("NICK", "", nick);
}

const StatusCode StatusCode::MSG_USER(int is_registered) {
    return StatusCode("USER", " :User accepted" + std::string(is_registered ? " (new registered!)" : ""));
}

const StatusCode StatusCode::MSG_QUIT(std::string msg) {
    return StatusCode("QUIT", msg);
}

const StatusCode StatusCode::MSG_JOIN(std::string channel) {
    return StatusCode("JOIN", "", channel);
}

const StatusCode StatusCode::MSG_PART(std::string channelName, std::string username) {
    return StatusCode("PART", channelName + " :" + username + " has left");
}

const StatusCode StatusCode::MSG_PRIVMSG(std::string target, std::string text) {
    return StatusCode("PRIVMSG", ":" + text, target);
}

const StatusCode StatusCode::MSG_NOTICE(std::string target, std::string text) {
    return StatusCode("NOTICE", ":" + text, target);
}

const StatusCode StatusCode::RPL_TOPIC(std::string channel, std::string topic) {
    return StatusCode("332", channel + " :" + topic);
}

const StatusCode StatusCode::RPL_NOTOPIC(std::string channel) {
    return StatusCode("332", channel + " :No topic is set");
}

const StatusCode StatusCode::RPL_ENDOFNAMES(std::string channel) {
    return StatusCode("366", channel + " :End of /NAMES list");
}

const StatusCode StatusCode::RPL_NAMREPLY(std::string channel, std::vector<std::string> nicks) {
    std::string msg;

    for (std::vector<std::string>::iterator it = nicks.begin(); it != nicks.end(); ++it) {
        msg += *it + " ";
    }

    return StatusCode("353", "= " + channel + " :" + msg);
}

const StatusCode StatusCode::RPL_LIST(std::string channel, int userNum, std::string topic) {
    std::string str;
    std::stringstream ssInt;
    ssInt << userNum;

    str += channel + " " + ssInt.str();

    return StatusCode("322", str + " :" + topic);
}

const StatusCode StatusCode::RPL_LISTEND() {
    return StatusCode("323", " :End of /LIST");
}

const StatusCode StatusCode::RPL_CHANNELMODEIS(std::string channel, std::string mode, std::string param) {
    return StatusCode("324", channel + " " + mode + (param != "" ? " " + param : ""));
}

const StatusCode StatusCode::RPL_UMODEIS(std::string mode) {
    return StatusCode("221", mode);
}

const StatusCode StatusCode::ERR_UNKNOWNCOMMAND(std::string command) {
    return StatusCode("421", command + " :Unknown command");
}

const StatusCode StatusCode::ERR_NEEDMOREPARAMS(std::string command) {
    return StatusCode("461", command + " :Not enough parameters");
}

const StatusCode StatusCode::ERR_ALREADYREGISTRED() {
    return StatusCode("462", " :You may not reregister");
}

const StatusCode StatusCode::ERR_PASSWDMISMATCH() {
    return StatusCode("464", " :Password incorrect");
}

const StatusCode StatusCode::ERR_NONICKNAMEGIVEN() {
    return StatusCode("431", " :No nickname given");
}

const StatusCode StatusCode::ERR_NICKNAMEINUSE(std::string nickname) {
    return StatusCode("433", nickname + " :Nickname is already in use");
}

const StatusCode StatusCode::ERR_ERRONEUSNICKNAME(std::string nickname) {
    return StatusCode("432", nickname + " :Erroneous nickname");
}

const StatusCode StatusCode::ERR_BADCHANMASK(std::string channel) {
    return StatusCode("476", channel + " :Bad Channel Mask");
}

const StatusCode StatusCode::ERR_NOTREGISTERED() {
    return StatusCode("451", " :You have not registered");
}

const StatusCode StatusCode::ERR_NOSUCHCHANNEL(std::string channel) {
    return StatusCode("403", channel + " :No such channel");
}

const StatusCode StatusCode::ERR_NOTONCHANNEL(std::string channel) {
    return StatusCode("442", channel + " :You're not on that channel");
}

const StatusCode StatusCode::ERR_NORECIPIENT(std::string command) {
    return StatusCode("411", " :No recipient given (" + command + ")");
}

const StatusCode StatusCode::ERR_NOTEXTTOSEND() {
    return StatusCode("412", " :No text to send");
}

const StatusCode StatusCode::ERR_TOOMANYTARGETS(std::string target) {
    return StatusCode("407", target + " :Duplicate recipients. No message delivered");
}

const StatusCode StatusCode::ERR_CANNOTSENDTOCHAN(std::string channel) {
    return StatusCode("404", channel + " :Cannot send to channel");
}

const StatusCode StatusCode::ERR_NOSUCHNICK(std::string nickname) {
    return StatusCode("401", nickname + " :No such nick/channel");
}

const StatusCode StatusCode::ERR_CHANOPRIVSNEEDED(std::string channel) {
    return StatusCode("482", channel + " :You're not channel operator");
}

const StatusCode StatusCode::ERR_UNKNOWNMODE(std::string mode) {
    return StatusCode("472", mode + " :is unknown mode char to me");
}

const StatusCode StatusCode::ERR_USERSDONTMATCH() {
    return StatusCode("502", ":Cannot change mode for other users");
}

const StatusCode StatusCode::ERR_UMODEUNKNOWNFLAG() {
    return StatusCode("501", ":Unknown MODE flag");
}