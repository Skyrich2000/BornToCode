#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

#include "Controller.hpp"
#include "Event.hpp"
#include "Message.hpp"
#include "arpa/inet.h"

// select 는 fd 변경이 감지 될떄까지 block 되고 있다. 따라서 IO Multiplexing으로 보는것같다!
// fd_read 에 1 을넣어둔 fd 만 관찰대상이 된다!

struct Buffer {
    std::string read;
    std::string write;
    bool isQuit;
};

class Network {
   private:
    const int port;
    const Controller* const controller;
    Event* const event;

    int listen_fd;
    std::map<int, Buffer> fds;
    std::set<int> toCloseFds;
    fd_set fd_read;
    fd_set fd_write;

    Network();
    Network(const Network& obj);

    Network& operator=(const Network& obj);

    void setupFd();
    int updateFd();
    void acceptFd();

    void recvMessage(int fd, Buffer& buffer);
    void sendMessage(int fd, Buffer& buffer);

   public:
    Network(int port, Controller* const controller, Event* const event);
    ~Network();

    void run();
};

#endif
