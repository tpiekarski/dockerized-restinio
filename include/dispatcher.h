#ifndef DOCKERIZED_RESTINIO_DISPATCHER_H
#define DOCKERIZED_RESTINIO_DISPATCHER_H

#include "controller/readyness-controller.h"

#include <restinio/request_handler.hpp>
#include <restinio/common_types.hpp>

using restinio::http_method_get;
using restinio::request_handle_t;
using restinio::request_handling_status_t;
using restinio::request_rejected;

namespace dockerized_restinio {
class Dispatcher {

  public:
    request_handling_status_t operator() (request_handle_t request) {
      if (http_method_get() != request->header().method()) {
        return request_rejected();
      }

      ReadynessController readynessController;

      if (request->header().request_target() == readynessController.getRoute()) {
        return readynessController.handleRequest(request);
      }

      return request_rejected();
    }

};
} // ns dockerized_restinio

#endif