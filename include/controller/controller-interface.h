#ifndef DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE
#define DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE

#include <restinio/request_handler.hpp>

namespace dockerized_restinio {
class ControllerInterface {

  public:
    virtual ~ControllerInterface() {}
    virtual restinio::request_handling_status_t handleRequest(restinio::request_handle_t request) = 0;

};
} // ns dockerized_restinio

#endif