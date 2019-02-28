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