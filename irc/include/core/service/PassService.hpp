#ifndef PASSSERVICE_HPP
#define PASSSERVICE_HPP

#include "Repository.hpp"
#include "Service.hpp"

class PassService : public Service {
   private:
    PassService();
    PassService& operator=(const PassService& obj);
    PassService(const PassService& obj);

   public:
    PassService(Repository* const repository, Event* const event);
    virtual ~PassService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
