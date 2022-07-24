#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <map>
#include <string>
#include <vector>

#include "Message.hpp"
#include "QuitService.hpp"
#include "Service.hpp"
#include "UserMiddleware.hpp"

class Controller {
   private:
    UserMiddleware *userMiddleware;
    std::map<std::string, Service *const> services;  // ex NICK

    Controller();
    Controller(const Controller &obj);

    Controller &operator=(const Controller &obj);

   public:
    Controller(UserMiddleware *const userMiddleware);
    virtual ~Controller();

    void addService(const std::string &command, Service *const service);

    const std::vector<Message> execute(const Message &req) const;  //특정 service를 실행하는 멤버함수
};

#endif