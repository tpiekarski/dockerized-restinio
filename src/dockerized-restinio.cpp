/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */


#include <iostream>
#include <restinio/all.hpp>
#include <string>

#include "dispatcher.h"
#include "options.h"

using namespace dockerized_restinio;
using std::cout;
using std::string;

int main(int argc, char* argv[]) {
  Options options;
  options.parse(argc, argv);

  cout << "Starting RESTinio HTTP/Websocket server at " << options.getAddress() << ':' << options.getPort() << '\n';

  restinio::run(
    restinio::on_this_thread()
      .address(options.getAddress())
      .port(options.getPort())
      .request_handler(Dispatcher())
  );

  return 0;
}