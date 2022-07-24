#ifndef TOPICSERVICE_HPP
#define TOPICSERVICE_HPP

#include "Repository.hpp"
#include "Service.hpp"

class TopicService : public Service {
   private:
    TopicService();
    TopicService& operator=(const TopicService& obj);
    TopicService(const TopicService& obj);

   public:
    TopicService(Repository* const repository, Event* const event);
    virtual ~TopicService();

    const std::vector<Message> execute(User* user, const std::vector<std::string>& param);
};

#endif
