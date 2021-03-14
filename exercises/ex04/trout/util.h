#ifndef UTIL_H
#define UTIL_H

#include "trout.h"

int pipe(int *fds);
ssize_t read(int fd, void *ptr, size_t nbytes);
size_t write(int fd, void *ptr, size_t nbytes);

char *icmpcode_v4(int code);
#endif
