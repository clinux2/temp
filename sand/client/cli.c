#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <poll.h>

#include "cli.h"
#include "utils/utils.h"

void Cli_setup(Cli *cli)
{
    // Create socket
    cli->serv_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Connect
    cli->addr.sin_family = AF_INET;
    cli->addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERV_IP, &cli->addr.sin_addr);
    cli->socklen = sizeof(cli->addr);

    connect(cli->serv_fd, (struct sockaddr *)&cli->addr, cli->socklen);
    printf("Connected\n");
}
void Cli_del(Cli *cli) { close(cli->serv_fd); }

int main()
{
    Cli cli;
    Cli_setup(&cli);
    Cli_run(&cli);
    Cli_del(&cli);
}

void Cli_run(Cli *cli)
{
    char buff_send[BUFFERSIZE];
    char buff_recv[BUFFERSIZE];

    while (1) {
        // Sendingg

        // get_string_input(buff_send, BUFFERSIZE);
    //     printf("Cli-host: %s\n", buff_send);
    //     Cli_send_msg(cli->serv_fd, buff_send, BUFFERSIZE);

    //     // Receiving
    //     Cli_receive_msg(cli->serv_fd, buff_recv, BUFFERSIZE);
    //     printf("Cli-guest: %s\n", buff_recv);
    }
}

static int Cli_send_msg(int serv_fd, JsonReq* req)
{
    
}

static int Cli_recv_msg(int serv_fd, JsonRes* res)
{

}