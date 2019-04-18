/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#ifndef DOCKERIZED_RESTINIO_READYNESS_CONTROLLER_H
#define DOCKERIZED_RESTINIO_READYNESS_CONTROLLER_H

#include <string>
#include <restinio/request_handler.hpp>

#include "controller-interface.h"
#include "route.h"

using restinio::request_handle_t;
using restinio::request_handling_status_t;
using std::string;

namespace dockerized_restinio {
class ReadynessController : public ControllerInterface {

  public:
    ReadynessController() : route({"/ready", httpMethod::GET}) {};
    ReadynessController(const ReadynessController& other) = default;
    ReadynessController(ReadynessController&& other) = default;

    request_handling_status_t handleRequest(request_handle_t request);
    request_handling_status_t operator() (request_handle_t request) { return handleRequest(request); }

    Route getRoute() { return route; }

  private:
    const Route route;

};
} // ns dockerized_restinio

#endif