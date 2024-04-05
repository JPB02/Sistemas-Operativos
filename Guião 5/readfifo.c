#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {

    int fd = open("fifo", O_RDONLY);
    if(fd<0) {
        perror("erro a abrir fifo");
    }

    printf("open: readfifo\n");

    return 0;
}