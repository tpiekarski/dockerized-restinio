/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */


#include <iostream>
#include <restinio/all.hpp>
#include <string>

#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

#include "dispatcher.h"

using namespace dockerized_restinio;
using std::cout;
using std::string;

const int DEFAULT_PORT = 8080;
const string DEFAULT_ADDRESS = "0.0.0.0";

int main(int argc, char* argv[]) {

  int port;
  string address;

  bpo::options_description optionsDescription("Allowed options");
  optionsDescription.add_options()
    ("port", bpo::value<int>(&port)->default_value(DEFAULT_PORT), "Port")
    ("address", bpo::value<string>(&address)->default_value(DEFAULT_ADDRESS), "Address");
  bpo::variables_map variablesMap;
  bpo::store(bpo::parse_command_line(argc, argv, optionsDescription), variablesMap);
  bpo::notify(variablesMap);

  cout << "Starting RESTinio HTTP/Websocket server at " << address << ':' << port << '\n';

  restinio::run(
    restinio::on_this_thread()
      .port(port)
      .address(address)
      .request_handler(Dispatcher())
  );

  return 0;
}