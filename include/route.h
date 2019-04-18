/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#ifndef DOCKERIZED_RESTINIO_ROUTE_H
#define DOCKERIZED_RESTINIO_ROUTE_H

#include <string>

using std::string;

namespace dockerized_restinio {

enum httpMethod {
  GET, POST, PUT, PATCH, DELETE
};

struct Route {
  string endpoint;
  httpMethod method;
};

} // ns dockerizes_restinio

#endif