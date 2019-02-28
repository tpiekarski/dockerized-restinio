#ifndef DOCKERIZED_RESTINIO_DISPATCHER_H
#define DOCKERIZED_RESTINIO_DISPATCHER_H

#include "controller/readyness-controller.h"

#include <memory>
#include <restinio/request_handler.hpp>
#include <restinio/common_types.hpp>

using restinio::http_method_get;
using restinio::request_handle_t;
using restinio::request_handling_status_t;
using restinio::request_rejected;
using std::unique_ptr;

namespace dockerized_restinio {
class Dispatcher {

  public:

    request_handling_status_t operator() (request_handle_t request) {
      if (http_method_get() != request->header().method()) {
        return request_rejected();
      }


      unique_ptr<ControllerInterface> controller(new ReadynessController()); 

      if (request->header().request_target() == controller->getRoute().endpoint) {
        return controller->handleRequest(request);
      }

      return request_rejected();
    }

};
} // ns dockerized_restinio

#endif