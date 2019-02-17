#ifndef DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE_H
#define DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE_H

#include <string>
#include <restinio/request_handler.hpp>

namespace dockerized_restinio {
class ControllerInterface {

  public:
    virtual ~ControllerInterface() {}

    virtual restinio::request_handling_status_t handleRequest(restinio::request_handle_t request) = 0;
    virtual std::string getRoute() = 0;
    
};
} // ns dockerized_restinio

#endif