#include <Server.hpp>

namespace nngrpc 
{

Server::Server(ServerChannel &channel) : m_channel(channel) {};

void Server::Register(Service &service)
{
    m_services.emplace(service.name(), std::ref(service));
}

}
