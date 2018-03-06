#include <asio.hpp>
#include <iostream>

using namespace std;
using asio::ip::udp;

int main(int argc, char* argv[]) {
  asio::io_service service;

  udp::resolver resolver(service);
  udp::resolver::query query(udp::v4(), argv[1], argv[2]);
  auto it = resolver.resolve(query);
  udp::socket socket(service);
  socket.open(udp::v4());
  socket.send_to(asio::buffer(string(stoi(argv[3]), 'x')), *it);
}
