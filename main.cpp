#include "adapter_http_server.h"

#include <iostream>

int main() {

  auto x = test(0);

  // start a simple http server using pistache framework
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));

  auto opts = Pistache::Http::Endpoint::options().threads(1);
  Pistache::Http::Endpoint server(addr);
  Pistache::Rest::Router router = makeAdapterHandler();
  server.init(opts);
  server.setHandler(router.handler());

  std::cout << "Server Ready to Run: " << std::endl;
  server.serve();


}
