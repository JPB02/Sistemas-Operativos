#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int fd = open("fifo", O_RDONLY);
    if(fd<0) {
        perror("erro a abrir fifo");
    }

    printf("open: readfifo\n");

    char buffer[1024];
    int res;
    while((res = read(fd, buffer,1024)) > 0) {
        write(1,buffer, res);
    }

    close(fd);

    //unlink("fifo");

    return 0;
}