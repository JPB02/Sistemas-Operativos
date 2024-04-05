#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int fd = open("fifo", O_WRONLY);
    if(fd<0) {
        perror("erro a abrir fifo");
    }

    printf("open: writefifo\n");

    char buffer[1024];
    int res;
    while((res = read(0, buffer,1024)) > 0) {
        write(fd,buffer, res);
    }

    close(fd);

    return 0;
}