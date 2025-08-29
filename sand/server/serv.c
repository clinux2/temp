#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "serv.h"

void Serv_setup(Serv* serv)
{
    //Creating socket
    serv->serv_fd = socket(AF_INET, SOCK_STREAM, 0);

    serv->opt = 1;
    setsockopt(serv->serv_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &serv->opt,
                   sizeof(serv->opt));
 
    //Binding
    serv->addr.sin_family = AF_INET;
    serv->addr.sin_addr.s_addr = INADDR_ANY;
    serv->addr.sin_port = htons(PORT);
    
    bind(serv->serv_fd, (struct sockaddr*)&serv->addr, sizeof(serv->addr));

    //Listening
    listen(serv->serv_fd, BACKLOG);
    printf("Listenning\n");

}
int Serv_accept_cli(Serv* setup)
{
    //Accepting
    int cli_fd = accept(setup->serv_fd, (struct sockaddr*)&setup->addr, &setup->socklen);
    printf("Accepted\n");
    return cli_fd;
}
void Serv_del(Serv* serv)
{
    close(serv->serv_fd);
}

void Serv_run(Serv* serv)
{
    printf("Hello, I am the fuking server\n");
    char buff[BUFFERSIZE];
    size_t buff_send_len;
    int cli_fd1, cli_fd2;
    
    cli_fd1 = Serv_accept_cli(serv);
    cli_fd2 = Serv_accept_cli(serv);
    
    // while (1)
    for (int i=0; i<4; i++)
    {
        printf("Let's started\n");
        
        //Receive from cli 1
        buff_send_len = Serv_receive_msg(cli_fd1, buff, BUFFERSIZE);
        // printf("Recevied(%d) from cli 1: %s\n",buff_send_len, buff);
        writeToFile("chat.txt", buff, "cli 1");
        //Send to cli 2
        Serv_send_msg(cli_fd2, buff, BUFFERSIZE); 
        printf("Cli 2: %s\n", buff);
        
        //Receive from cli 2
        buff_send_len = Serv_receive_msg(cli_fd2, buff, BUFFERSIZE);
        writeToFile("chat.txt", buff, "cli 2");
        // printf("Recevied from cli 2: %s\n", buff);
        
        //Send to cli 1
        Serv_send_msg(cli_fd1, buff, BUFFERSIZE); 
        printf("Sent to cli 1: %s\n", buff);
    }
}
    



static int Serv_send_msg(int cli_fd, const char* msg, size_t msglen)
{
    int n = send(cli_fd, msg, msglen - 1, 0);
    return n;
}

static int Serv_receive_msg(int cli_fd, char* buff, size_t bufflen)
{
    size_t total_received = 0;
    ssize_t bytes_received;

    if (bufflen == 0) return -1;

    while (total_received < bufflen - 1) {
        bytes_received = recv(cli_fd, buff + total_received, bufflen - 1 - total_received, 0);
        if (bytes_received <= 0) {
            // Connection closed or error
            break;
        }
        total_received += bytes_received;
    }
    
    buff[total_received] = '\0'; // Null-terminate
    return total_received;
}

static void writeToFile(const char *filename, const char *text, const char* who) 
{
    FILE *file = fopen(filename, "a");  // Open file for writing ("w" mode)
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fprintf(file, "%s%s%s", who, text, "\n");  // Write the text to the file
    printf("File works\n");
    fclose(file);  // Close the file
}

int main()
{
    Serv serv;
    Serv_setup(&serv);
    Serv_run(&serv);
    Serv_del(&serv);
}