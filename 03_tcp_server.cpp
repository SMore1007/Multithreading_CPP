#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

int main()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return 1;
    }

    std::cout << "Winsock initialized successfully" << std::endl;

    WSACleanup(); // Cleanup Winsock
    return 0;
}
