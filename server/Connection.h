/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Connection.h
*/

#ifndef BABEL_CONNECTION_H
#define BABEL_CONNECTION_H

#include <boost/asio.hpp>
#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/make_shared.hpp>
#include <boost/chrono.hpp>

using boost::asio::ip::tcp;

class Connection: public boost::enable_shared_from_this<Connection>
{
    public:
        ~Connection() = default;

        static boost::shared_ptr<Connection> createConnection(boost::asio::io_service &io_service);
        tcp::socket &getSocket();
        void closeSocket(boost::system::error_code &ec);
        int writeMessage(std::string msg);
        void startRead();
        void onRead(const boost::system::error_code &error, std::size_t bytes_transferred);
    private:
        Connection(boost::asio::io_service &ioService);

        tcp::socket _sock;
        boost::asio::streambuf _buffer;
};

#endif //BABEL_CONNECTION_H
