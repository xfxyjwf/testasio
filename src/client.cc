#include <asio.hpp>
#include <iostream>

using namespace std;
using asio::ip::tcp;

int main(int argc, char* argv[]) {
  asio::io_service service;

  tcp::resolver resolver(service);
  tcp::resolver::query query(argv[1], argv[2]);
  tcp::socket socket(service);
  asio::connect(socket, resolver.resolve(query));

  cout << "Command: " << flush;
  string cmd;
  while (cin >> cmd) {
    if (cmd == "send") {
      socket.shutdown(tcp::socket::shutdown_send);
    } else if (cmd == "receive") {
      socket.shutdown(tcp::socket::shutdown_receive);
    } else if (cmd == "both") {
      socket.shutdown(tcp::socket::shutdown_both);
    } else if (cmd == "close") {
      socket.close();
    } else if (cmd == "exit") {
      break;
    } else {
      cerr << "Unknown command: " << cmd << endl;
    }
  }
}
