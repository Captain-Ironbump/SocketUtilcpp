#ifndef SOCKETUTIL_H
#define SOCKETUTIL_H

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>  // Include Windows-specific networking headers
    #pragma comment(lib, "ws2_32.lib")  // Link against Winsock library

    // Initialize Winsock (this is needed only for Windows)
    #define INIT_WINSOCK() \
        do { \
            WSADATA wsaData; \
            if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) { \
                fprintf(stderr, "WSAStartup failed\n"); \
                return NULL; \
            } \
        } while(0)
    #define CLEANUP_WINSOCK() WSACleanup()

#else
    #include <sys/socket.h>  // POSIX socket headers for Linux/macOS
    #include <netinet/in.h>
    #include <arpa/inet.h>
#endif

#ifdef __APPLE__
    #include <stdlib.h>
#elif defined(__linux__)
    #include <malloc.h>
#endif

struct sockaddr_in* createIPv4SockAddr(const char* ip, int port);
int createTCPIPv4Socket();

#endif // !SOCKETUTIL_H
