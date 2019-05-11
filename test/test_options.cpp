/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#define BOOST_TEST_MODULE "TestOptions"

#include "options.h"
#include <sstream>
#include <string>
#include <vector>
#include <boost/test/unit_test.hpp>

using std::ostringstream;
using std::string;
using std::vector;
using namespace dockerized_restinio;

BOOST_AUTO_TEST_CASE(test_default_options) {
  Options options;

  BOOST_CHECK_EQUAL(options.address(), "0.0.0.0");
  BOOST_CHECK_EQUAL(options.port(), 8080);
}

BOOST_AUTO_TEST_CASE(test_parsing_all_options) {
  vector<char*> argv;
  argv.push_back((char*) "test");
  argv.push_back((char*) "--address");
  argv.push_back((char*) "127.0.0.1");
  argv.push_back((char*) "--port");
  argv.push_back((char*) "8085");

  Options options;
  options.parse(argv.size(), argv.data());

  BOOST_CHECK_EQUAL(options.address(), "127.0.0.1");
  BOOST_CHECK_EQUAL(options.port(), 8085);
}

BOOST_AUTO_TEST_CASE(test_parsing_address_option) {
  vector<char*> argv;
  argv.push_back((char*) "test");
  argv.push_back((char*) "--address");
  argv.push_back((char*) "192.168.0.5");

  Options options;
  options.parse(argv.size(), argv.data());

  BOOST_CHECK_EQUAL(options.address(), "192.168.0.5");
  BOOST_CHECK_EQUAL(options.port(), 8080);
}

BOOST_AUTO_TEST_CASE(test_parsing_port_option) {
  vector<char*> argv;
  argv.push_back((char*) "test");
  argv.push_back((char*) "--port");
  argv.push_back((char*) "8085");

  Options options;
  options.parse(argv.size(), argv.data());

  BOOST_CHECK_EQUAL(options.address(), "0.0.0.0");
  BOOST_CHECK_EQUAL(options.port(), 8085);
}

BOOST_AUTO_TEST_CASE(test_overloaded_output_stream) {
  Options options;
  ostringstream test_stream;

  test_stream << options;

  BOOST_CHECK_EQUAL(test_stream.str(), "0.0.0.0:8080");
}
