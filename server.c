#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    int udp_socket;
    char msg[100];
    struct sockaddr_in dir;

    if (argc != 2) {
        printf("Uso: %s PUERTO\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *port = argv[1];

    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&dir, 0, sizeof(struct sockaddr_in));
    dir.sin_family = AF_INET;
    dir.sin_port = htons(atoi(port));
    dir.sin_addr.s_addr = INADDR_ANY;

    bind(udp_socket, (struct sockaddr*) &dir, sizeof(dir));

    while (recv(udp_socket, msg, sizeof(msg), 0)) { 
        printf("%s\n", msg);
    }

    exit(EXIT_SUCCESS);
}
