#ifndef UTIL_H
#define UTIL_H

int pipe(int *fds);
ssize_t read(int fd, void *ptr, size_t nbytes);
size_t write(int fd, void *ptr, size_t nbytes);

#endif
