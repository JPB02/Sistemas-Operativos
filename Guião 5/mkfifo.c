#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {

    if(mkfifo("fifo", 0666) < 0) {
        perror("erro a criar o fifo");
    }



    return 0;
}