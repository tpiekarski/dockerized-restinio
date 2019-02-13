#ifndef DOCKERIZED_RESTINIO_READYNESS_CONTROLLER
#define DOCKERIZED_RESTINIO_READYNESS_CONTROLLER

#include <restinio/request_handler.hpp>

using restinio::request_handle_t;
using restinio::request_handling_status_t;

namespace dockerized_restinio {
class ReadynessController {

  public:
    ReadynessController() = default;
    ReadynessController(const ReadynessController& other) = default;
    ReadynessController(ReadynessController&& other) = default;

    request_handling_status_t requestHandler(request_handle_t request);
    request_handling_status_t operator() (request_handle_t request) { return requestHandler(request); }

};
} // ns dockerized_restinio

#endif