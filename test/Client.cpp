#include <Client.hpp>

namespace nngrpc
{

Client::Client(ClientChannel &channel) : m_channel(channel) {};

Reply Client::call(const Request &request) {

    std::vector<uint8_t> srzRequest(request.ByteSizeLong());
    request.SerializeToArray(srzRequest.data(), srzRequest.size());

    m_channel.send(srzRequest);
    const auto &srzReply = m_channel.recv();

    Reply reply;
    reply.ParseFromArray(srzReply.data(), srzReply.size());

    return reply;
}

}
