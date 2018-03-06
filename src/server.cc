#include <asio.hpp>
#include <iostream>
#include <string>
#include <memory>

using namespace std;
using asio::ip::udp;

char buffer[10 * 1024];

string ToString(const udp::endpoint& endpoint) {
  return endpoint.address().to_string() + ":" + to_string(endpoint.port());
}

void StartReceive(udp::socket* socket) {
  auto remote = make_shared<udp::endpoint>();
  socket->async_receive_from(asio::buffer(buffer), *remote, [socket, remote](const asio::error_code& ec, size_t len) {
    if (ec) {
      cerr << ec.message() << endl;
      return;
    }
    cout << "Received " << len << " bytes " << ToString(*remote) << endl;
    StartReceive(socket);
  });
}

int main() {
  asio::io_service service;
  udp::socket socket(service, udp::endpoint(udp::v4(), 11234));
  StartReceive(&socket);
  service.run();
}
