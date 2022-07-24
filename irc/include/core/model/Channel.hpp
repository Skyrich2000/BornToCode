#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>

class Channel {
   private:
    std::string name;
    std::string topic;
    std::string mode;

    Channel();

   public:
    Channel(const std::string& name);
    Channel(const Channel& obj);
    ~Channel();

    Channel& operator=(const Channel& obj);
    bool operator==(const Channel& obj) const;

    const std::string& getName() const;
    const std::string& getTopic() const;
    const std::string& getMode() const;
    bool isMode(char mode) const;

    void setTopic(const std::string& str);
    void addMode(char mode);
    void removeMode(char mode);
};

#endif
