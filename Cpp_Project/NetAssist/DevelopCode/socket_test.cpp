/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-24 11:36:51
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2026-03-12 17:18:51
 * @Description: Life is struggle.
 */
#ifndef SOCKET_H
#define SOCKET_H

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#endif

#include <string>
#include <stdexcept>
#include <stdio.h>
#include <Windows.h>
#include <thread>
#include <mutex>
using namespace std;

class Socket
{
public:
    Socket();
    ~Socket();

    // 创建 socket
    void create();

    // 绑定地址和端口
    void bind(const std::string &address, int port);

    // 监听连接
    void listen(int backlog = 5);

    // 接受连接
    Socket accept();

    // 连接到服务器
    void connect(const std::string &address, int port);

    // 发送数据
    int send(const std::string &data);

    // 接收数据
    std::string receive(int bufferSize = 4096);

    // 关闭 socket
    void close();

    // 获取 socket 描述符
    SOCKET getSocket() const;

    int clear();

    int reconnect();

private:
    SOCKET sockfd;          // socket 描述符
    bool isClosed;          // 标记 socket 是否已关闭
    std::string ip_address; // ip 地址
    int port;               // 端口

    // 初始化网络库（Windows 需要）
    void initNetwork();

    // 清理网络库（Windows 需要）
    void cleanupNetwork();
};

#endif // SOCKET_H

// 实现部分
#include <iostream>
Socket::Socket() : sockfd(INVALID_SOCKET), isClosed(true)
{
    initNetwork();
}

Socket::~Socket()
{
    if (!isClosed)
    {
        close();
    }
    cleanupNetwork();
}

void Socket::initNetwork()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        throw std::runtime_error("WSAStartup failed");
    }
#endif
}

void Socket::cleanupNetwork()
{
#ifdef _WIN32
    WSACleanup();
#endif
}

void Socket::create()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET)
    {
        throw std::runtime_error("Failed to create socket");
    }
    isClosed = false;
}

void Socket::bind(const std::string &address, int port)
{
    if (sockfd == INVALID_SOCKET)
    {
        throw std::runtime_error("Socket not created");
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    // 暂不支持 inet_pton，改用 inet_addr
    // inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr);
    serverAddr.sin_addr.s_addr = inet_addr(address.c_str());
    if (serverAddr.sin_addr.s_addr == INADDR_NONE)
    {
        throw std::runtime_error("Invalid address");
    }

    if (::bind(sockfd, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        throw std::runtime_error("Failed to bind socket");
    }
}

void Socket::listen(int backlog)
{
    if (::listen(sockfd, backlog) == SOCKET_ERROR)
    {
        throw std::runtime_error("Failed to listen on socket");
    }
}

Socket Socket::accept()
{
    sockaddr_in clientAddr{};
    socklen_t clientAddrLen = sizeof(clientAddr);

    SOCKET clientSock = ::accept(sockfd, (sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSock == INVALID_SOCKET)
    {
        throw std::runtime_error("Failed to accept connection");
    }

    Socket clientSocket;
    clientSocket.sockfd = clientSock;
    clientSocket.isClosed = false;
    return clientSocket;
}

void Socket::connect(const std::string &address, int port)
{
    if (sockfd == INVALID_SOCKET)
    {
        throw std::runtime_error("Socket not created");
    }

    this->ip_address = address;
    this->port = port;

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    // 暂不支持 inet_pton，改用 inet_addr
    // inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr);
    serverAddr.sin_addr.s_addr = inet_addr(address.c_str());
    if (serverAddr.sin_addr.s_addr == INADDR_NONE)
    {
        throw std::runtime_error("Invalid address");
    }

    if (::connect(sockfd, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        throw std::runtime_error("Failed to connect to server");
    }

    unsigned long on = 1;
    ioctlsocket(sockfd, FIONBIO, (unsigned long *)&on);
}

int Socket::send(const std::string &data)
{
    int bytesSent = ::send(sockfd, data.c_str(), data.size(), 0);
    if (bytesSent == SOCKET_ERROR)
    {
        std::cout << "Send reconnect, p_address: " << this << std::endl;
        reconnect();
    }
    return bytesSent;
}

std::string Socket::receive(int bufferSize)
{
    int ret = 0;
    int rlen = 0;
    int times = 20;
    char *buffer = new char[bufferSize + 1]{};

    while (rlen < bufferSize && times > 0)
    {
        ret = ::recv(sockfd, buffer + rlen, bufferSize - rlen, 0);
        if (ret < 1)
        {
            times--;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        else
        {
            rlen += ret;
        }
    }

    std::string data;
    if (rlen == 0)
    {
        std::cout << "Receive reconnect, p_address: " << this << std::endl;
        reconnect();
    }
    else
    {
        data = std::string(buffer, bufferSize);
    }
    delete[] buffer;
    return data;
}

void Socket::close()
{
    if (!isClosed)
    {
#ifdef _WIN32
        if (sockfd != INVALID_SOCKET)
        {
            // 2. 配置 SO_LINGER，确保发送 FIN 而非 RST
            // struct linger lin;
            // lin.l_onoff = 1;
            // lin.l_linger = 5; // 等待5秒
            // setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *)&lin, sizeof(lin));
            shutdown(sockfd, SD_SEND);

            auto start_time = chrono::high_resolution_clock::now();
            float time = 0;
            char recvBytes[2048] = { 0 };
            while (time < 1000)
            {
                Sleep(100); // 等待5秒，确保发送 FIN 包
                unsigned long pending = 0;
                ioctlsocket(sockfd, FIONREAD, &pending);
                if (pending == 0) {
                    break;
                }
                else
                {
                    recv(sockfd, recvBytes, 2048, 0);
                }
                auto end_time = chrono::high_resolution_clock::now();
                time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            }
            cout << "wait for send FIN package cost: " << time << " ms" << endl;
            // Sleep(1000); // 等待5秒，确保发送 FIN 包
            closesocket(sockfd);
            sockfd = INVALID_SOCKET;
        }

#else
        ::close(sockfd);
#endif
        isClosed = true;
    }
}

SOCKET Socket::getSocket() const
{
    return sockfd;
}

int Socket::clear()
{
    char recvBytes[2048] = {0};
    unsigned long bytes = 0;
    ioctlsocket(sockfd, FIONREAD, &bytes);
    if (bytes > 0)
    {
        recv(sockfd, recvBytes, 2048, 0);
    }
    return 0;
}

int Socket::reconnect()
{
    try
    {
        std::cout << "try to reconnect" << std::endl;
        close();

        // 重新连接
        create();
        connect(ip_address, port);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}

void test_socket_reconnect()
{
    char config[] = "./config.ini";
    char rst[64] = {0};
    GetPrivateProfileStringA("Config", "ip1", "0", rst, 64, config);
    std::string ip1 = rst;
    int port1 = GetPrivateProfileIntA("Config", "port1", 0, config);

    GetPrivateProfileStringA("Config", "ip2", "0", rst, 64, config);
    std::string ip2 = rst;
    int port2 = GetPrivateProfileIntA("Config", "port2", 0, config);

    cout << "ip1: " << ip1 << ", port1: " << port1 << std::endl;
    cout << "ip2: " << ip2 << ", port2: " << port2 << std::endl;

    bool is_stop1 = false;
    bool is_stop2 = false;
    std::mutex mtx1; // 全局互斥锁
    std::mutex mtx2; // 全局互斥锁

    Socket client1;
    Socket client2;
    client1.create();
    client1.connect(ip1, port1);
    client2.create();
    client2.connect(ip2, port2);

    // 创建线程
    auto thread1 = std::make_shared<std::thread>([&]()
                                                 {
        string message;
        while (is_stop1 == false)
        {
            mtx1.lock();
            client1.clear();
            this_thread::sleep_for(chrono::milliseconds(200));
            message = client1.receive(100);
            if (message.empty())
            {
                cout << "client1 receive: empty" << endl;
            }
            else
            {
                cout << "client1 receive: xxxx, " << message << endl;
            }
            mtx1.unlock();
            this_thread::sleep_for(chrono::milliseconds(1000));
        } });
    auto thread2 = std::make_shared<std::thread>([&]()
                                                 {
        string message;
        char pWriteBytes[9] = { 0x01,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
        int move_count = 1;

        while (is_stop2 == false)
        {
            mtx2.lock();
            pWriteBytes[4] = (0xff000000 & move_count) >> 24;
            pWriteBytes[5] = (0x00ff0000 & move_count) >> 16;
            pWriteBytes[6] = (0x0000ff00 & move_count) >> 8;
            pWriteBytes[7] = 0x000000ff & move_count;
            for (int j = 0; j < 8; j++)
            {
                pWriteBytes[8] += pWriteBytes[j];
            }
            string send_data = string(pWriteBytes, 9);
            client2.send(send_data);
            this_thread::sleep_for(chrono::milliseconds(500));
            message = client2.receive(100);
            if (message.empty())
            {
                cout << "client2 receive: empty" << endl;
            }
            else
            {
                cout << "client2 receive: xxxx, " << message << endl;
            }
            move_count++;
            mtx2.unlock();
            this_thread::sleep_for(chrono::milliseconds(1000));
        } });

    // 业务逻辑
    int cin_code = 0;
    while (true)
    {
        // cin_code = GetPrivateProfileIntA("Config", "cin_code", 0, config);
        cin >> cin_code;
        if (cin_code == 0)
        {
            cout << "*** nothing happend ***" << endl;
            continue;
        }
        else if (cin_code == 1)
        {
            mtx1.lock();
            cout << "*** client1 shutdown ***" << endl;
            client1.close();
            mtx1.unlock();
        }
        else if (cin_code == 2)
        {
            mtx2.lock();
            cout << "*** client2 shutdown ***" << endl;
            client2.close();
            mtx2.unlock();
        }
        else if (cin_code == -1)
        {
            cout << "exit" << endl;
            break;
        }
    }

    is_stop1 = true;
    is_stop2 = true;

    thread1->join();
    thread2->join();
    client1.close();
    client2.close();
}

int main()
{
    test_socket_reconnect();
    // SOCKET sockfd;
    // char *buffer = new char[100]{};
    // int bytesRead = ::recv(sockfd, buffer, 100, 0);
    // delete[] buffer;
    // cout << "bytesRead: " << bytesRead << endl;
    return 0;
}
