#include "src/adapter_http_server.h"

#include <iostream>

int main() {

  // start a simple http server using pistache framework
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));

  auto opts = Pistache::Http::Endpoint::options().threads(1);
  Pistache::Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(std::make_shared<BucketNotificationHandler>());

  std::cout << "Server Ready to Run: " << std::endl;
  server.serve();


}
