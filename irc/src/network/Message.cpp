#include "Message.hpp"

Message::Message() : fd(0), command(), targetName(), param(), nickname(), username(), hostname(), isQuit(false) {}

Message::Message(int fd, const std::string& command, const std::string& targetName, const std::vector<std::string>& param, const std::string& nickname, const std::string& username, const std::string& hostname, const bool isQuit) : fd(fd), command(command), targetName(targetName), param(param), nickname(nickname), username(username), hostname(hostname), isQuit(isQuit) {}

Message::Message(const Message& obj) : fd(obj.fd), command(obj.command), targetName(obj.targetName), param(obj.param), nickname(obj.nickname), username(obj.username), hostname(obj.hostname), isQuit(obj.isQuit) {}

Message::~Message() {}

Message& Message::operator=(const Message& obj) {
    (void)obj;
    return (*this);
}

const std::string Message::toRawString() const {
    std::string rawString = ":";

    if (nickname != "") {
        rawString += nickname;
        if (username != "")
            rawString += "!" + username;
        if (hostname != "")
            rawString += "@" + hostname;
        rawString += " ";
    }

    rawString += command + " ";
    if (targetName != "")
        rawString += targetName + " ";

    rawString += Util::join(param, ' ');
    rawString += "\r\n";
    return rawString;
}

const Message Message::create(int fd, const std::string& rawstring) {
    std::string str = rawstring;
    std::vector<std::string> tokens = Util::split(Util::trim(str), ' ');

    for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        Util::trim(*it);
    }

    if (tokens.size() < 1)
        throw std::runtime_error("Invalid message");

    for (std::vector<std::string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr) {
        if ((*itr)[0] == ':') {
            (*itr).erase(0, 1);
            *itr = Util::join(std::vector<std::string>(itr, tokens.end()), ' ');
            tokens.erase(itr + 1, tokens.end());
            break;
        }
    }

    return Message(fd, tokens.front(), "", std::vector<std::string>(tokens.begin() + 1, tokens.end()), "", "", "");
}

const Message Message::create(User* from, User* to, const StatusCode& statusCode) {
    std::string target = statusCode.targetName == "" ? to->nickname : statusCode.targetName;
    bool isQuit = false;

    if (statusCode.code == "QUIT" && from->getFd() == to->getFd()) {
        isQuit = true;
    }

    return Message(to->getFd(), statusCode.code, target, std::vector<std::string>(1, statusCode.message), from->nickname, from->username, from->hostname, isQuit);
}

std::ostream& operator<<(std::ostream& os, const Message& msg) {
    std::string str = msg.toRawString();
    os << msg.fd << " - " << Util::rtrim(str);
    return os;
}
