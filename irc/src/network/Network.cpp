#include "Network.hpp"

Network::Network() : port(4000), controller(NULL), event(NULL) {
    this->setupFd();
}

Network::Network(int port, Controller* const controller, Event* const event) : port(port), controller(controller), event(event) {
    this->setupFd();
}

Network::Network(const Network& obj) : port(obj.port), controller(obj.controller), event(obj.event) {
    this->setupFd();
}

Network::~Network() {}

Network& Network::operator=(const Network& obj) {
    (void)obj;
    return *this;
}

void Network::setupFd() {
    this->listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->listen_fd < 0) {
        throw std::runtime_error("socket failed");
    }
    fcntl(this->listen_fd, F_SETFL, O_NONBLOCK);
    std::cout << "listening... fd: " << this->listen_fd << std::endl;

    int op = 1;
    if (setsockopt(this->listen_fd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op)) < 0) {
        throw std::runtime_error("setsockopt failed");
    }

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(this->port);

    if (bind(this->listen_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        throw std::runtime_error("bind failed");
    }

    if (listen(this->listen_fd, 42) < 0) {
        throw std::runtime_error("listen failed");
    }
}

void Network::acceptFd() {
    struct sockaddr_in addr;
    socklen_t client_addr_len = sizeof(addr);
    int client_fd = accept(this->listen_fd, (struct sockaddr*)&addr, &client_addr_len);
    if (client_fd == -1) {
        throw std::runtime_error("accept failed");
    }

    fcntl(client_fd, F_SETFL, O_NONBLOCK);

    std::cout << "New client #" << client_fd << " from " << inet_ntoa(addr.sin_addr) << ":" << ntohs(addr.sin_port) << std::endl;
    Buffer buf;
    buf.read = "";
    buf.write = "";
    buf.isQuit = false;
    this->fds.insert(std::make_pair(client_fd, buf));
}

int Network::updateFd() {
    int maxFd = this->listen_fd;

    FD_ZERO(&this->fd_read);
    FD_ZERO(&this->fd_write);
    FD_SET(this->listen_fd, &this->fd_read);
    for (std::map<int, Buffer>::iterator it = this->fds.begin(); it != this->fds.end(); ++it) {
        int fd = it->first;
        maxFd = std::max(maxFd, fd);
        FD_SET(fd, &this->fd_read);
        if (!it->second.write.empty()) {
            FD_SET(fd, &this->fd_write);
        }
    }
    return select(maxFd + 1, &this->fd_read, &this->fd_write, NULL, NULL);
}

void Network::recvMessage(int fd, Buffer& buffer) {
    if (buffer.isQuit)
        return;

    char buf[512];
    int n = recv(fd, buf, sizeof(buf), 0);

    if (n <= 0) {
        event->push(Message::create(fd, "QUIT"));
        return;
    }

    buffer.read.append(buf, n);

    size_t pos;
    while ((pos = buffer.read.find("\r\n")) != std::string::npos) {
        std::string message = buffer.read.substr(0, pos);
        buffer.read.erase(0, pos + 2);
        event->push(Message::create(fd, message));
    }
}

void Network::sendMessage(int fd, Buffer& buffer) {
    if (send(fd, buffer.write.c_str(), buffer.write.size(), 0) < 0)
        return;
    buffer.write.clear();

    if (buffer.write.empty() && buffer.isQuit) {
        this->toCloseFds.insert(fd);
    }
}

void Network::run() {
    while (true) {
        int r = this->updateFd();
        if (r == -1) {
            continue;
        }

        if (FD_ISSET(this->listen_fd, &this->fd_read)) {
            this->acceptFd();
        }

        for (std::map<int, Buffer>::iterator it = this->fds.begin(); it != this->fds.end(); ++it) {
            int fd = it->first;
            try {
                if (FD_ISSET(fd, &this->fd_read))
                    this->recvMessage(fd, it->second);
                if (FD_ISSET(fd, &this->fd_write))
                    this->sendMessage(fd, it->second);
            } catch (const std::exception& e) {
                std::cout << "Request  : " << fd << " - Empty String Recived" << std::endl;
            }
        }

        while (!this->event->isEmpty()) {
            const Message req = this->event->pop();
            std::cout << "Request  : " << req << std::endl;

            const std::vector<Message> res = this->controller->execute(req);
            for (std::vector<Message>::const_iterator it = res.begin(); it != res.end(); ++it) {
                std::cout << "Response : " << *it << std::endl;

                if (it->isQuit)
                    this->fds[it->fd].isQuit = true;
                this->fds[it->fd].write.append(it->toRawString());
            }
        }

        for (std::set<int>::iterator it = this->toCloseFds.begin(); it != this->toCloseFds.end(); ++it) {
            int fd = *it;
            close(fd);
            std::cout << "client #" << fd << " gone away" << std::endl;
            this->fds.erase(fd);
        }
        this->toCloseFds.clear();
    }
}
