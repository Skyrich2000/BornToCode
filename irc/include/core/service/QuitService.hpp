#ifndef QUITSERVICE_HPP
#define QUITSERVICE_HPP

#include "Repository.hpp"
#include "Service.hpp"

class QuitService : public Service {
   private:
    QuitService();
    QuitService& operator=(const QuitService& obj);
    QuitService(const QuitService& obj);

   public:
    QuitService(Repository* const repository, Event* const event);
    virtual ~QuitService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
