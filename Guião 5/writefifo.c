#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {

    int fd = open("fifo", O_WRONLY);
    if(fd<0) {
        perror("erro a abrir fifo");
    }

    printf("open: writefifo\n");

    return 0;
}