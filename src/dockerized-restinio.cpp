/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#include <iostream>
#include <restinio/all.hpp>

#include "dispatcher.h"

using dockerized_restinio::Dispatcher;
using std::cout;

int main(int argc, char* argv[]) {
  cout << "Starting RESTinio HTTP/Websocket server" << '\n';

  restinio::run(
    restinio::on_this_thread()
      .port(8080)
      .address("0.0.0.0")
      .request_handler(Dispatcher())
  );

  return 0;
}