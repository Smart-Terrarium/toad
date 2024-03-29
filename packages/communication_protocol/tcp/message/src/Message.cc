#include "toad/communication_protocol/tcp/message/Message.hh"
#include "toad/communication_protocol/tcp/message/Identifier.hh"
#include "toad/communication_protocol/tcp/message/Payload.hh"
#include <cstdint>
#include <string>
#include <tuple>

namespace toad::communication_protocol::tcp
{
Message::Message(const clientId_t &clientId, const Type &type, const Purpose &purpose, const Payload &payload) :
    id_{}, clientId_{clientId}, type_{type}, purpose_{purpose}, payload_{payload}
{
}

uuid Message::getId() const
{
    return id_.id;
}

Message::clientId_t Message::getClientId() const
{
    return clientId_;
}

Payload::buffer_t Message::getRawPayload() const
{
    return payload_.getPayload();
}

Payload Message::getPayload() const
{
    return payload_;
}

Message::Type Message::getType() const
{
    return type_;
}

Message::Purpose Message::getPurpose() const
{
    return purpose_;
}

bool Message::operator==(const Message &rhs) const
{
    return std::tie(clientId_, type_, purpose_, payload_) ==
           std::tie(rhs.clientId_, rhs.type_, rhs.purpose_, rhs.payload_);
}

bool Message::operator!=(const Message &rhs) const
{
    return !(rhs == *this);
}

Message MessageFactory::createAlertReport(const Message::clientId_t &clientId, const Payload &payload)
{
    return Message{clientId, Message::Type::report, Message::Purpose::alert, payload};
}

Message MessageFactory::createAlertIndicationReport(const Message::clientId_t &clientId, const Payload &payload)
{
    return Message{clientId, Message::Type::report, Message::Purpose::alertIndication, payload};
}

Message MessageFactory::createGetConfigurationRequest(const Message::clientId_t &clientId, const Payload &payload)
{
    return Message{clientId, Message::Type::request, Message::Purpose::getConfiguration, payload};
}

Message MessageFactory::createGetConfigurationResponse(const Message::clientId_t &clientId, const Payload &payload)
{
    return Message{clientId, Message::Type::response, Message::Purpose::getConfiguration, payload};
}

Message MessageFactory::createFailureResponse(const Message::clientId_t &clientId, const Payload &payload)
{
    return Message{clientId, Message::Type::response, Message::Purpose::failure, payload};
}
} // namespace toad::communication_protocol::tcp

#include "toad/communication_protocol/tcp/message/formatter/Message.tpp"