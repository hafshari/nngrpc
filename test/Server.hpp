#pragma once

#include <nngrpc.pb.h>
#include <Channel.hpp>
#include <string>
#include <Service.hpp>
#include <unordered_map>
#include <functional>

namespace nngrpc 
{

class Server {
public:
    Server(ServerChannel &);
    void Register(Service &);
    void start();
private:
    Channel &m_channel;
    std::unordered_map<std::string, std::reference_wrapper<Service>> m_services;
};

}
