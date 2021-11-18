#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <memory>

#include "request.h"
#include "response.h"
#include "router.h"

class Connection : public boost::enable_shared_from_this<Connection>,
                   private boost::noncopyable {
 public:
  explicit Connection(boost::asio::io_context& io_context);

  boost::asio::ip::tcp::socket& socket();
  void start();

 private:
  void handle_read(const boost::system::error_code& e,
                   std::size_t bytes_transferred);
  void handle_write(const boost::system::error_code& e);

  boost::asio::strand<boost::asio::io_context::executor_type> strand;
  boost::asio::ip::tcp::socket socket_;
  boost::array<char, 8192> buffer;
  Router requestRouter;
  
  Request request;
  Response response;
};

#endif