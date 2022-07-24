#include "ModeService.hpp"

ModeService::ModeService() : Service() {}

ModeService::ModeService(Repository* const repository, Event* const event) : Service(repository, event) {}

ModeService::ModeService(const ModeService& obj) : Service(obj) {}

ModeService::~ModeService() {}

ModeService& ModeService::operator=(const ModeService& obj) {
    (void)obj;
    return (*this);
}

const std::vector<Message> ModeService::modeChannel(User* user, const std::vector<std::string>& param) {
    std::string channelName = param[0];

    Channel* channel = this->repository->getChannelByName(channelName);
    if (channel == NULL) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_NOSUCHCHANNEL(channelName)));
    }

    if (param.size() == 1) {
        std::string _mode = channel->getMode();
        return std::vector<Message>(1, Message::create(server, user, StatusCode::RPL_CHANNELMODEIS(channelName, _mode != "" ? "+" + _mode : "")));
    }

    UserInChannel* userInChannel = this->repository->getUserInChannel(user, channel);
    if (userInChannel == NULL || !userInChannel->is_operator) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_CHANOPRIVSNEEDED(channelName)));
    }

    if (param[1].size() < 2 || std::string("+-").find(param[1][0]) == std::string::npos || std::string("otn").find(param[1][1]) == std::string::npos) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_UNKNOWNMODE(param[1])));
    }

    char op = param[1][0];
    char mode = param[1][1];

    // 이미 들어간 mode 예외 처리

    if (mode == 'o') {
        if (param.size() != 3) {
            return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_UNKNOWNMODE(param[1])));
        }

        std::string nickname = param[2];
        User* targetUser = repository->getUserByNickname(nickname);
        if (targetUser == NULL) {
            return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_NOSUCHNICK(nickname)));
        }

        UserInChannel* targetUserInChannel = repository->getUserInChannel(targetUser, channel);
        if (targetUserInChannel == NULL) {
            return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_NOTONCHANNEL(channelName)));
        }

        if (op == '+') {
            targetUserInChannel->is_operator = true;
        } else {
            targetUserInChannel->is_operator = false;
        }
    }

    if (op == '+') {
        channel->addMode(mode);
    } else if (op == '-') {
        channel->removeMode(mode);
    }

    return std::vector<Message>(1, Message::create(server, user, StatusCode::RPL_CHANNELMODEIS(channelName, param[1], param.size() > 2 ? param[2] : "")));
}

const std::vector<Message> ModeService::modeUser(User* user, const std::vector<std::string>& param) {
    std::string nickname = param[0];

    if (*param.begin() != user->nickname) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_USERSDONTMATCH()));
    }

    if (param.size() == 1) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::RPL_UMODEIS("")));
    }

    return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_UMODEUNKNOWNFLAG()));
}

const std::vector<Message> ModeService::execute(User* user, const std::vector<std::string>& param) {
    if (!user->isRegistered()) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_NOTREGISTERED()));
    }

    if (param.size() == 0) {
        return std::vector<Message>(1, Message::create(server, user, StatusCode::ERR_NEEDMOREPARAMS("MODE")));
    }

    std::string target = param[0];
    if (target[0] == '#') {
        return (modeChannel(user, param));
    } else {
        return (modeUser(user, param));
    }
}
