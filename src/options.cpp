/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#include "options.h"

namespace dockerized_restinio {

const string Options::DEFAULT_ADDRESS = "0.0.0.0";
const int Options::DEFAULT_PORT = 8080;

Options::Options() : 
  optionsDescription(new bpo::options_description("RESTinio Options")),
  variablesMap(new bpo::variables_map()),
  address(Options::DEFAULT_ADDRESS), 
  port(Options::DEFAULT_PORT)
{
  optionsDescription->add_options()
    ("address", bpo::value<string>(&address)->default_value(Options::DEFAULT_ADDRESS), "Address")
    ("port", bpo::value<int>(&port)->default_value(Options::DEFAULT_PORT), "Port");
}

Options::~Options() {
  if (optionsDescription != nullptr) {
    delete optionsDescription;
    optionsDescription = nullptr;
  }

  if (variablesMap != nullptr) {
    delete variablesMap;
    variablesMap = nullptr;
  }
}

void Options::parse(int argc, char* argv[]) {
  bpo::store(bpo::parse_command_line(argc, argv, *optionsDescription), *variablesMap);
  bpo::notify(*variablesMap);
}

} // ns dockerized_restinio