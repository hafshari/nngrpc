#pragma once

#include <nngrpc.pb.h>

#include <functional>

namespace nngrpc 
{

class Server {
public:
    Server(const Channel &);
    void Register(const Service &);
private:
    const Channel &m_channel;
};

}
