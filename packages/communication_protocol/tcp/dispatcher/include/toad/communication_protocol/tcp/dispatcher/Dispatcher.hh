#pragma once
#include "toad/communication_protocol/tcp/broker/Broker.hh"
#include "toad/communication_protocol/tcp/message/Hub.hh"
#include "toad/communication_protocol/tcp/notifier/Notifier.hh"
#include "toad/communication_protocol/tcp/requester/Requester.hh"

namespace toad::communication_protocol::tcp
{
class Dispatcher
{
  private:
    Hub& hub_;
    Broker& broker_;
    Requester& requester_;
    Notifier& notifier_;

  public:
    Dispatcher(Hub&, Broker&, Requester&, Notifier&);
    void start();
};
} // namespace toad::communication_protocol::tcp
