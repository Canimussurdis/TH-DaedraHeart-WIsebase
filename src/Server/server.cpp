#include "server.h"

#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <thread>
#include <vector>

server::server(const std::string& address, const std::string& port,
               std::size_t thread_pool_size)
    : thread_pool_size(thread_pool_size), acceptor(io_context), connection() {
  /* Some logic */
}

void server::run() { /* Some logic */ }

void server::start_accept() { /* Some logic */ }

void server::handle_accept(const boost::system::error_code& e) {
  /* Some logic */
}