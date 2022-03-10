#pragma once

#include <nngrpc.pb.h>

#include <Channel.hpp>

namespace nngrpc 
{

class Client {
public:
    Client(ClientChannel &);
    Reply call(const Request &);
private:
    Channel &m_channel;
};

}
