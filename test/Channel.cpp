#include <Channel.hpp>

namespace nngrpc 
{

void Channel::send(const std::vector<uint8_t> &){}
std::vector<uint8_t> Channel::recv(){ return {};}

ServerChannel::ServerChannel(const std::string &url){}
void ServerChannel::listen(){}

ClientChannel::ClientChannel(const std::string &url){}
void ClientChannel::dial(){}

}
