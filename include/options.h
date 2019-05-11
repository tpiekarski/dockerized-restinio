/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#ifndef DOCKERIZED_RESTINIO_OPTIONS_H
#define DOCKERIZED_RESTINIO_OPTIONS_H

#include <iostream>
#include <string>

#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

using std::ostream;
using std::string;

namespace dockerized_restinio {

class Options {

  public:
    Options();
    Options(const Options& other) = default;
    Options(Options&& other) = default;

    ~Options();

    void parse(int argc, char* argv[]);

    string address() { return address_; }
    int port() { return port_; }

    friend ostream& operator<<(ostream& os, Options& options);

  private:
    static const string DEFAULT_ADDRESS;
    static const int DEFAULT_PORT;

    bpo::options_description *optionsDescription_;
    bpo::variables_map *variablesMap_;
    
    string address_;
    int port_;

};
} // ns dockerized_restinio

#endif