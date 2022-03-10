#pragma once

#include <string>

#include <nngrpc.pb.h>

namespace nngrpc 
{

class Service {
public:
    std::string name() {return {};};
    Reply invoke(const Request &) {return {};};
};

}
