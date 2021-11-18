#include "connection.h"

#include <boost/bind/bind.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Connection::Connection(
    boost::asio::io_context& io_context)
    : strand(boost::asio::make_strand(io_context)),
      socket_(strand),
      requestRouter() {}

boost::asio::ip::tcp::socket& Connection::socket() { /* Some logic */
}

void Connection::start() { /* Some logic */
}

void Connection::handle_read(const boost::system::error_code& e,
                             std::size_t bytes_transferred) {
  /* Some logic */
}

void Connection::handle_write(const boost::system::error_code& e) {
  /* Some logic */
}