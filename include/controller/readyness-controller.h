#ifndef DOCKERIZED_RESTINIO_READYNESS_CONTROLLER
#define DOCKERIZED_RESTINIO_READYNESS_CONTROLLER

#include <string>
#include <restinio/request_handler.hpp>

#include "controller-interface.h"

using restinio::request_handle_t;
using restinio::request_handling_status_t;
using std::string;

namespace dockerized_restinio {
class ReadynessController : public ControllerInterface {

  public:
    ReadynessController() = default;
    ReadynessController(const ReadynessController& other) = default;
    ReadynessController(ReadynessController&& other) = default;

    request_handling_status_t handleRequest(request_handle_t request);
    request_handling_status_t operator() (request_handle_t request) { return handleRequest(request); }

  private:
    static const string route;

};
} // ns dockerized_restinio

#endif