#ifndef MODESERVICE_HPP
#define MODESERVICE_HPP

#include "Event.hpp"
#include "Message.hpp"
#include "Repository.hpp"
#include "Service.hpp"

class ModeService : public Service {
   private:
    ModeService();
    ModeService& operator=(const ModeService& obj);
    ModeService(const ModeService& obj);

   public:
    ModeService(Repository* const repository, Event* const event);
    virtual ~ModeService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
    const std::vector<Message> modeChannel(User* user, const std::vector<std::string>& param);
    const std::vector<Message> modeUser(User* user, const std::vector<std::string>& param);
};

#endif
