#pragma once

#include <nngrpc.pb.h>

namespace nngrpc 
{

class Client {
public:
    Client(const Channel &);
    Reply call(const Request &);
private:
    const Channel &m_channel;
};

}
