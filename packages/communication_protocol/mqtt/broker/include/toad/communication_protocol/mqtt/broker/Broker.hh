#pragma once
#include "toad/communication_protocol/mqtt/broker/interface/Broker.hh"
#include "toad/communication_protocol/mqtt/broker/interface/BrokerEventHandler.hh"
#include <memory>
#include <mqtt_server_cpp.hpp>

namespace toad::communication_protocol
{
class Endpoint;
} // namespace toad::communication_protocol

namespace toad::communication_protocol::mqtt
{
class Broker : public interface::Broker
{
  private:
    std::unique_ptr<interface::BrokerEventHandler> brokerEventHandler_{};

    boost::asio::io_context brokerAcceptor_{};
    using mqttServer_t = ::MQTT_NS::server<>;
    mqttServer_t broker_;

    void listen();
    void accept();
    void setupHandleOnConnection();
    void setupHandleOnError();

  public:
    Broker(const Broker&) = delete;
    Broker& operator=(const Broker&) = delete;
    Broker(Broker&&) = delete;
    Broker& operator=(Broker&&) = delete;
    ~Broker() = default;
    Broker(const Endpoint&, std::unique_ptr<interface::BrokerEventHandler>);
    bool start() override;
};
} // namespace toad::communication_protocol::mqtt