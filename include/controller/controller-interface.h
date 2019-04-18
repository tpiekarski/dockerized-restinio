/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 */

#ifndef DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE_H
#define DOCKERIZED_RESTINIO_CONTROLLER_INTERFACE_H

#include <string>
#include <restinio/request_handler.hpp>

#include "route.h"

namespace dockerized_restinio {
class ControllerInterface {

  public:
    virtual ~ControllerInterface() {}

    virtual restinio::request_handling_status_t handleRequest(restinio::request_handle_t request) = 0;
    virtual Route getRoute() = 0;
    
};
} // ns dockerized_restinio

#endif