#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <uninstd.h>

int main(int argc, char *argv[]){ 
    extern char *optarg;
    extern int optind;
    int option_val = 0;
    int port_number = 7000;
    int sock;
    char *message;
    int mflag = 0;
    struct sockaddr_in server;
    struct hostent *hp;
    char buff[1024];
    while ((option_val = getopt(argc, argv, "p:m:"))){
        switch(option_val){
            case 'p':
                port_number = atoi(optarg);
                break;
            case 'm':
                mflag = 1;
                message = optarg;
                break;
            case '?':
                printf("you must type a meesage after the -m option\n");
        }
    }
    if(mflag == 0){
        printf("missing -m option");
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket failed");
        exit(1);
    }
    server.sin_family = AF_INET;
    hp = gethostbyname (*argv[1]);
    if(hp == 0){
        perror("gethostbyname failed");
        close(sock);
        exit(1);
    }
    memccpy(&server.sin_addr, hp->h_addr, hp->h_length);
    server.sin_port = htons(port_number);

    if(connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0){
        perror("connect failed");
        close(sock);
        exit(1);
    }
    if(send(sock, message sizeof(message),0) < 0){
        perror("send failed");
        close(sock);
        exit(1);
    }
    printf("Sent %s\n", message);
    close(sock);
    
    
    return 0;
}