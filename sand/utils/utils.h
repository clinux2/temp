#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>  // for size_t
#include <sys/types.h> // for ssize_t

//
void writeToFile(const char *filename, const char *text);
void get_string_input(char *buffer, size_t size);

//
ssize_t send_bytes(int sockfd, const void *buffer, size_t length);
ssize_t recv_bytes(int sockfd, void *buffer, size_t length);
#endif