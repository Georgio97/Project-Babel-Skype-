/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** ServerManager.cpp
*/

#include "ServerManager.h"

ServerManager::ServerManager()
{
    _ioService = boost::shared_ptr<boost::asio::io_service>(new boost::asio::io_service);
    _work = boost::shared_ptr<boost::asio::io_service::work>(new boost::asio::io_service::work(*_ioService));
    _strand = boost::shared_ptr<boost::asio::io_service::strand>(new boost::asio::io_service::strand(*_ioService));
    _acceptor = boost::shared_ptr<boost::asio::ip::tcp::acceptor>(new boost::asio::ip::tcp::acceptor(*_ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234)));

    for (int x = 0; x < 4; x++)
        _workerThreads.create_thread(boost::bind(&ServerManager::createWorkerThread, this));
}

ServerManager::~ServerManager()
{
    _ioService->stop();
    _workerThreads.join_all();
}

void ServerManager::createWorkerThread()
{
    boost::system::error_code ec;

    _streamLock.lock();
    std::cout << "[" << boost::this_thread::get_id()
              << "] Thread Start" << std::endl;
    _streamLock.unlock();
    while (true)
    {
        try
        {
            _ioService->run(ec);
            if (ec)
            {
                _streamLock.lock();
                std::cout << "[" << boost::this_thread::get_id()
                          << "] Error: " << ec << std::endl;
                _streamLock.unlock();
            }
            break;
        }
        catch (std::exception &ex)
        {
            _streamLock.lock();
            std::cout << "[" << boost::this_thread::get_id()
                      << "] Exception: " << ex.what() << std::endl;
            _streamLock.unlock();
        }
    }
    _streamLock.lock();
    std::cout << "[" << boost::this_thread::get_id()
              << "] Thread Finish" << std::endl;
    _streamLock.unlock();
}

void ServerManager::startAccept()
{
    _streamLock.lock();
    _connections.push_back(Connection::createConnection(*_ioService));
    _acceptor->async_accept(
            _connections.back()->getSocket(),
            boost::bind(&ServerManager::onAccept, this, _1, _connections.back())
    );
    std::cout << "Connections size: " << _connections.size() << std::endl;
    _streamLock.unlock();
}

void ServerManager::onAccept(const boost::system::error_code &ec, boost::shared_ptr<Connection> connection)
{
    if (ec) {
        _streamLock.lock();
        std::cout << "[" << boost::this_thread::get_id()
                  << "] onAccept: " << ec << std::endl;
        _streamLock.unlock();
    } else {
        _streamLock.lock();
        std::cout << "[" << boost::this_thread::get_id()
                  << "] Accepted!" << std::endl;
        connection->writeMessage("Successfully connected !!\n");
        connection->startRead();
        _strand->post(boost::bind(&ServerManager::startAccept, this));
        _streamLock.unlock();
    }
}

int ServerManager::launchServer()
{
    boost::system::error_code ec;

    try {
        _strand->post(boost::bind(&ServerManager::startAccept, this));
    } catch (std::exception &e) {
        _streamLock.lock();
        std::cout << "Error message: " << e.what() << std::endl;
        _streamLock.unlock();
    }
    std::cin.get();
    _acceptor->close(ec);
    return 0;
}
