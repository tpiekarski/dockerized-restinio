/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#ifndef DOCKERIZED_RESTINIO_DISPATCHER_H
#define DOCKERIZED_RESTINIO_DISPATCHER_H

#include "controller/readyness-controller.h"

#include <map>
#include <memory>
#include <restinio/request_handler.hpp>
#include <restinio/common_types.hpp>

using restinio::http_method_get;
using restinio::request_handle_t;
using restinio::request_handling_status_t;
using restinio::request_rejected;
using std::map;
using std::unique_ptr;

namespace dockerized_restinio {

template<typename T> ControllerInterface * createController() { return new T; };
typedef map<string, ControllerInterface * (*)()> controllerType;

class Dispatcher {

  public:

    request_handling_status_t operator() (request_handle_t request) {
      if (http_method_get() != request->header().method()) {
        return request_rejected();
      }

      controllerType routing;
      routing["/ready"] = &createController<ReadynessController>;

      if (routing[request->header().request_target()] == nullptr) {
        return request_rejected();
      }

      unique_ptr<ControllerInterface> controller(routing[request->header().request_target()]());

      return controller->handleRequest(request);
    }

};
} // ns dockerized_restinio

#endif