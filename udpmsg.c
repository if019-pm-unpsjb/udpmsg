#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

struct sockaddr_in obtener_direccion(int addr, int port)
{
    struct sockaddr_in dir;

    memset(&dir, 0, sizeof(struct sockaddr_in));

    dir.sin_family = AF_INET;
    dir.sin_port = htons(port);
    dir.sin_addr.s_addr = addr;

    return dir;
}

void client(char* dir, char* port, char* msg)
{
    int udp_socket;

    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in dest_addr = obtener_direccion(inet_addr(dir), atoi(port));

    socklen_t dest_addr_len = sizeof(dest_addr);

    sendto(udp_socket, msg, strlen(msg) + 1, 0, 
            (struct sockaddr*) &dest_addr, dest_addr_len);
}

void server(int port)
{
    int udp_socket;

    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in dest_addr = obtener_direccion(INADDR_ANY, port);

    bind(udp_socket, (struct sockaddr*) &dest_addr, sizeof(dest_addr));

    char msg[100];

    while (recv(udp_socket, msg, 100, 0)) { 
        printf("%s\n", msg);
    }
}

int main(int argc, char* argv[]) {

    char mode = argv[1][1];

    switch(mode) {
        case 'c':
            client(argv[2], argv[3], argv[4]);
            break;
        case 's':
            server(atoi(argv[2]));
            break;
        default:
            exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
