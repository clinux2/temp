#include <stdio.h>
#include <unistd.h>  // for close()
#include <sys/types.h>
#include <sys/socket.h>  // for socket functions

#include "utils.h"

void writeToFile(const char *filename, const char *text)
{
    FILE *file = fopen(filename, "w");  // Open file for writing ("w" mode)
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", text);  // Write the text to the file

    fclose(file);  // Close the file
}

void get_string_input(char *buffer, size_t size)
{
    if (fgets(buffer, size, stdin)) {
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

//
ssize_t send_bytes(int sockfd, const void *buffer, size_t length)
{
    size_t total_sent = 0;
    const char *data = buffer;

    while (total_sent < length) {
        ssize_t bytes_sent = send(sockfd, data + total_sent, length - total_sent, 0);
        if (bytes_sent <= 0) {
            perror("send failed");
            return -1;
        }
        total_sent += bytes_sent;
    }

    return total_sent;
}

ssize_t recv_bytes(int sockfd, void *buffer, size_t length)
{
    size_t total_received = 0;
    char *data = buffer;

    while (total_received < length) {
        ssize_t bytes_received = recv(sockfd, data + total_received, length - total_received, 0);
        if (bytes_received < 0) {
            perror("recv failed");
            return -1;
        } else if (bytes_received == 0) {
            // Connection closed by peer
            break;
        }
        total_received += bytes_received;
    }

    return total_received;
}
