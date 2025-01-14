#include "socketUtil.h"

struct sockaddr_in* createIPv4SockAddr(const char* ip, int port) {
    struct sockaddr_in* addr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    memset(addr, 0, sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    if (strlen(ip) == 0) {
        addr->sin_addr.s_addr = INADDR_ANY;
    } else {
#ifdef _WIN32
        if (InetPton(AF_INET, ip, &addr->sin_addr.s_addr) != 1) {
            fprintf(stderr, "InetPton failed\n");
            free(addr);
            return NULL;
        }
#else
        if (inet_pton(AF_INET, ip, &addr->sin_addr.s_addr) != 1) {
            fprintf(stderr, "inet_pton failed\n");
            free(addr);
            return NULL;
        }
#endif
    }
    return addr;
}

int createTCPIPv4Socket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}
