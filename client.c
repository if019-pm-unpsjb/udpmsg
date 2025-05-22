#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    int udp_socket;
    struct sockaddr_in dest;

    if (argc != 4) {
        printf("Uso: %s IP PUERTO MSG\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dir = argv[1];
    char *port = argv[2];
    char *msg = argv[3];

    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(atoi(port));
    dest.sin_addr.s_addr = inet_addr(dir);

    sendto(udp_socket, msg, strlen(msg) + 1, 0, 
            (struct sockaddr*) &dest, sizeof(dest));

    exit(EXIT_SUCCESS);
}
