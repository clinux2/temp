#ifndef SERV_H
#define SERV_H

#include <arpa/inet.h>

#include "../utils/json_re.h"

#define PORT 9000
#define BUFFERSIZE 4096
#define BACKLOG 10
#define LINE_SIZE 512

typedef struct Serv {
    int serv_fd;
    int opt;
    struct sockaddr_in addr;
    socklen_t socklen;
} Serv;

void Serv_setup(Serv *serv);      //
int Serv_accept_cli(Serv *serv);  //
void Serv_run(Serv *serv);        //
void Serv_del(Serv *serv);        //

static int Serv_send_res(int cli_fd, JsonReq* res);
static JsonReq* Serv_recv_req(int cli_fd);

#endif