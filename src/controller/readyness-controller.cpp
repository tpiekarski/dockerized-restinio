#include "controller/readyness-controller.h"

#include <restinio/http_headers.hpp>

using restinio::http_field;
using restinio::request_accepted;
using restinio::request_handle_t;
using restinio::request_handling_status_t;
using restinio::status_ok;

namespace dockerized_restinio {

request_handling_status_t ReadynessController::handleRequest(request_handle_t request) {
  request->create_response(status_ok())
    .append_header_date_field()
    .append_header(http_field::server, "RESTinio")
    .append_header(http_field::content_type, "text/plain; charset=utf-8")
    .done();

  return request_accepted();
}

} // ns dockerized_restinio