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
  optionsDescription_(new bpo::options_description("RESTinio Options")),
  variablesMap_(new bpo::variables_map()),
  address_(Options::DEFAULT_ADDRESS), 
  port_(Options::DEFAULT_PORT)
{
  optionsDescription_->add_options()
    ("address", bpo::value<string>(&address_)->default_value(Options::DEFAULT_ADDRESS), "Address")
    ("port", bpo::value<int>(&port_)->default_value(Options::DEFAULT_PORT), "Port");
}

Options::~Options() {
  if (optionsDescription_ != nullptr) {
    delete optionsDescription_;
    optionsDescription_ = nullptr;
  }

  if (variablesMap_ != nullptr) {
    delete variablesMap_;
    variablesMap_ = nullptr;
  }
}

void Options::parse(int argc, char* argv[]) {
  bpo::store(bpo::parse_command_line(argc, argv, *optionsDescription_), *variablesMap_);
  bpo::notify(*variablesMap_);
}

} // ns dockerized_restinio