/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Connection.cpp
*/

#include "Connection.h"

Connection::Connection(boost::asio::io_service &ioService): _sock(ioService)
{
}

int Connection::writeMessage(std::string msg)
{
    boost::system::error_code ec;

    try {
        boost::asio::write(_sock, boost::asio::buffer(msg), boost::asio::transfer_all(), ec);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

void Connection::closeSocket(boost::system::error_code &ec)
{
    _sock.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    _sock.close(ec);
}

boost::shared_ptr<Connection> Connection::createConnection(boost::asio::io_service &ioService)
{
    return boost::shared_ptr<Connection>(new Connection(ioService));
}

tcp::socket &Connection::getSocket()
{
    return _sock;
}

void Connection::onRead(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    std::cout << "Handler onRead()" << std::endl;
//    std::string s(boost::asio::buffer_cast<const char *>(_buffer.data()), _buffer.size());
//    std::cout << "Message recv => " <<s << std::endl;
//    startRead();
}

void Connection::startRead()
{
    try {
        std::cout << "startRead() Begin" << std::endl;
        boost::asio::async_read(_sock, _buffer, boost::bind(&Connection::onRead, this, _1, _2));
        std::cout << "startRead() End" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}