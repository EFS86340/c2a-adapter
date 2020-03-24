#include "src/http_server.h"

#include <aws/core/Aws.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <iostream>

// using namespace Pistache;

int main() {

  // start a simple http server using pistache framework
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));

  auto opts = Pistache::Http::Endpoint::options().threads(1);
  Pistache::Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(std::make_shared<HelloHandler>());
  server.serve();

  // Aws::SDKOptions options;
  // options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
  // Aws::InitAPI(options);
  // {

  // }
  // Aws::ShutdownAPI(options);
  // return 0;
}
