/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#define BOOST_TEST_MODULE "TestOptions"

#include "options.h"
#include <boost/test/unit_test.hpp>

using namespace dockerized_restinio;

BOOST_AUTO_TEST_CASE(test_default_options) {
  Options options;

  BOOST_CHECK_EQUAL(options.address(), "0.0.0.0");
  BOOST_CHECK_EQUAL(options.port(), 8080);
}
