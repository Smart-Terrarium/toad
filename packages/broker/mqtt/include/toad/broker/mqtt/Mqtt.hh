#pragma once
#include "toad/broker/mqtt/interface/Mqtt.hh"
#include "toad/broker/mqtt/interface/EventHandler.hh"
#include <memory>
#include <mqtt_server_cpp.hpp>
#include "toad/network/endpoint/Endpoint.hh"

namespace toad::network
{
  using mqttServer_t = MQTT_NS::server<endpoint_t>;
}

namespace toad::broker::mqtt
{
class Mqtt : public interface::Mqtt
{
  private:
  boost::asio::io_context brokerContext_;
  toad::network::mqttServer_t broker_;
  std::unique_ptr<interface::EventHandler> eventHandler_{nullptr};

  public:
    Mqtt(const Mqtt&) = delete;
    Mqtt& operator=(const Mqtt&) = delete;

    ~Mqtt();
    Mqtt(Mqtt&&);
    Mqtt& operator=(Mqtt&&);
    Mqtt(const toad::network::Endpoint&, std::unique_ptr<interface::EventHandler>);

    bool start() override;
    bool stop() override;
    bool restart() override;
};
} // namespace toad::server::broker
