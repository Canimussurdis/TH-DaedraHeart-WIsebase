#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>

#include "connection.h"
#include "request.h"
#include "response.h"
#include "router.h"

class server : private boost::noncopyable {
 public:
  explicit server(const std::string& address, const std::string& port,
                  std::size_t thread_pool_size);
  void run();

 private:
  void start_accept();
  void handle_accept(const boost::system::error_code& e);

  std::size_t thread_pool_size;
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::acceptor acceptor;
  boost::shared_ptr<Connection> connection;
};

#endif
