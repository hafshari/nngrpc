#pragma once

#include <string>

#include <nngrpc.pb.h>

namespace nngrpc 
{

class Service {
public:
    virtual std::string name() = 0;
    virtual Reply handle(const Request &) = 0;
};

}
