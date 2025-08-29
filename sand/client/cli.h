#ifndef CLI_H
#define CLI_H

#include <arpa/inet.h>
// #include <sys/socket.h>
// #include <unistd.h>

#include "../utils/json_re.h"

#define SERV_IP "127.0.0.1"
#define PORT 9000
#define BUFFERSIZE 4096
#define LINE_SIZE 512

typedef struct Cli {
    int serv_fd;
    struct sockaddr_in addr;
    socklen_t socklen;
} Cli;

void Cli_setup(Cli *cli);  //
void Cli_del(Cli *cli);    //
void Cli_run(Cli *cli); //

static int Cli_send_msg(int serv_fd, JsonReq* req);  //
static int Cli_recv_msg(int serv_fd, JsonRes* res);   //

#endif