/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** ServerManager.h
*/

#ifndef BABEL_SERVERMANAGER_H
#define BABEL_SERVERMANAGER_H

#include "Connection.h"
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/make_shared.hpp>
#include <vector>

class ServerManager
{
    public:
        ServerManager();
        ~ServerManager();

        int launchServer();

    private:
        boost::mutex _streamLock;
        boost::thread_group _workerThreads;
        boost::shared_ptr<boost::asio::io_service> _ioService;
        boost::shared_ptr< boost::asio::io_service::work > _work;
        boost::shared_ptr< boost::asio::io_service::strand > _strand;
        boost::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
        std::vector<boost::shared_ptr<Connection>> _connections;

        void createWorkerThread();
        void startAccept();
        void onAccept(const boost::system::error_code &ec, boost::shared_ptr<Connection> connection);
};


#endif //BABEL_SERVERMANAGER_H
