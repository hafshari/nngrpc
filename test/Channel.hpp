#pragma once

namespace nngrpc 
{

class Channel {
public:
    send(const std::vector<uint8_t> &);
    std::vector<uint8_t> recv();
};

class ServerChannel : public Channel {
public:
    ServerChannel(const std::string &url);
private:
    void listen();
};

class ClientChannel : public Channel {
public:
    ClientChannel(const std::string &url);
private:
    void dial();
};

}
