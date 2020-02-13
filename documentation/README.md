</pre>#Babel_Project_2019

# CPP_babel_2019

## Team Work : Georges Rached, Gautier Plancq, Lucas Duboisse

## Getting Started

This document is a technical documentation about Babel. The Babel project aims to create an SIP-like Voice Over IP (VOIP) protocol. It MUST be usable over the Internet. 
We will firstly explain the project conception: it is divided in 2 parts. There is the Server and the Client. The server receives data from a client and transfers it to the others. Clients sends request to the server and get datas in order to call other clients.

### Prerequisites of the Project

What things you need to install the software and how to install them

```
git clone git@git.epitech.eu:/georges.rached@epitech.eu/CPP_babel_2019
```


## Built With Libraries

* [Qt](https://www.qt.io/) -  for the client’s graphical user interface, or any implementation detail on theclient side.
* [PortAudio](http://www.portaudio.com/) - for anything sound related
* [OPUS](http://www.opus-codec.org/) -  for the compression codec

### Installing the Libraires

A step by step series of examples that tell you how to get a development env running


For Qt :

```
https://www.qt.io/download
```

For PortAudio :

```
http://www.portaudio.com/download.html
```

For Opus :

```
http://www.opus-codec.org/downloads/
```


The project is an OS independent. It has to compile and run in a similar manner on Unix system and Windows systems.
It is built using a CMake and dependencies is handled using [Conan](https://conan.io/).

### Conception :

- #### TCP Connection :
    - In this subsection, we will explain the TCP Connection part of the client. It is the directly related to the Server-Client communication part : [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)
    - The main library that we used for our server is Boost since it is a crossplat-form really powerfull library for network and parsing purpose. It helps us to build a strong server with asynchronous multi client connections.
    - The Network class (which inherits from Network) has a TCPServer *server attribute and a void startAccept() method. This method launches the loop of the server.
    - The TCPServer class has a list of TCPConnection and a boost::asio::ip::tcp::acceptor for attribute, a void startAccept() and a void onAccept(TCPConnection::pointer newConnection, const boost::system::error_code error) methods in order to accept new connections and push them into the list of TCPConnection.
- #### UDP Connection :
    - In this subsection, we will explain the UDP Connection part of the client. It corresponds to the client to client connection : [UDP](https://en.wikipedia.org/wiki/User_Datagram_Protocol)


### Client :

In this section, we will see in details what we used for the client and how it was
thought.
  - #### Libraries chosen :
    - #### Port Audio
        - Firstly, we used Port Audio for sound related things. We chose it because it is an Open-Source Cross-Platfor Audio library recognized and used by many such as the free audio editor Audacity. It helps us to get sound from the computer’s microphone and to play it through it’s speakers.
        - Since it is a C library, we had to encapsulate it so here it is: our encapsulation of Port Audio.
        - It has two simple methods start() and stop() in order to start and stop recording or start and stop playing sound.
    - #### Opus
        - Then we used Opus for the compression codec. We chose it because it is a totally open and highly versatile audio codec (Skype uses it). It helps us to encode and decode our sound recorded with Port Audio in order to send the packages encoded and to decode them once received.
        - Since it is also a C library, we had to encapsulate it too.
        - It has two methods encode() and decode() returning structures with encoded and decoded data.
    - #### Qt
        - Finally, we used Qt for the Graphical User Interface and QtNetwork for all the network related things. We chose it because it is basically ranked 1 of all cross-platform tools and known powerfull for UIs and applications that runs on any operating system. Moreover, it is a native C++ library so we don’t have to encapsulate it. It helps us to build our GUI through a lot of Qt classes and to create TCP and UDP connections to server and clients.
        - Since it is a C++ library, we don’t need to encapsulate it. However, here is the very beginning of our network TCP class. It shows an example on how we use Qt.
        - Our class NetworkServerHandler inherits from the QObject Qt class (and our Network abstraction INetwork) and we use a pointer to a QTcpSocket to create our socket.



## Running CMake

See how to run cmake on Linux & Windows OS

[How to compile and excute with CMake](https://cmake.org/runningcmake/).


## Our documentaion
In our repository, go to our directory "/documentation".
You can see that there is a UML diagram class of our project : 'SIP-like Voice Over IP (VOIP) protocol..pdf'
Then you can see that there is a file named "README.md". However, I suggest you to use [Dillinger ](https://dillinger.io/) to execute our markdown file !

</pre>
