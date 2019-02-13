/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#include <iostream>
#include <restinio/all.hpp>
#include "router.h"

using std::cout;
using dockerized_restinio::Router;

// Routes
const string Router::readyness_route  = "/ready";
// ---

restinio::request_handling_status_t readynessHandler(restinio::request_handle_t req) {
  if (restinio::http_method_get() != req->header().method() || req->header().request_target() != Router::readyness_route) {
    return restinio::request_rejected();
  }

  req->create_response(restinio::status_ok())
    .append_header_date_field()
    .append_header(restinio::http_field::server, "RESTinio")
    .append_header(restinio::http_field::content_type, "text/plain; charset=utf-8")
    .done();

  return restinio::request_accepted();
}

int main(int argc, char* argv[]) {
  cout << "Starting RESTinio HTTP/Websocket server" << '\n';

  restinio::run(
    restinio::on_this_thread()
      .port(8080)
      .address("0.0.0.0")
      .request_handler(readynessHandler)
  );

  return 0;
}