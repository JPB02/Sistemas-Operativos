#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    fint valueExists(int **matrix, int value) {

    int pipefd[2];
    int ret = pipe(pipefd);
    if(ret < 0) {
        perror("Erro a criar pipe");
    }

    int linha;

    for(linha=0; linha<ROWS; linha++) {
        pid_t pid = fork();

        switch(pid) {
            case -1:
                perror("erro no fork");

            case 0:
                //filho
                int col;
                close(pipefd[0]);

                for(col=0; col<COLUMNS; col++) {
                    if(matrix[linha][col] == value) {

                        write(pipefd[1], &valor, sizeof(int));
                    }
                }

                close(pipefd[1]);
                _exit(0);

            default:
                //pai
                int res;
                close(pipefd[1]);

                while(read(pipefd[0], &res, sizeof(int)) > 0) {
                    printf("pai: recebi %d\n", res);
                }

                close(pipefd[0]);

                int status;
                wait(&status);
                res = WEXITSTATUS(status);
                if(WIFEXITED(status)) {
                    printf("filho terminou\n");
                }

                else {
                    perror("filho interrompido");
                }

                break;
        }
    }

}
or (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void lookupNumber(int** matrix, int value, int* vector){

    int pfd[2];
    pipe(pfd);



    for(int i=0; i<ROWS; i++) {
        pid_t pid = fork();

        if(pid==0) {
            //filho
            Minfo m;
            m.line_nr = i;
            m.ocur_nr = 0;

            close(pfd[0]);

            for(int j=0; j<COLUMNS; j++) {
                if(matrix[i][j] == value) {
                    m.ocur_nr++;
                }
            }

            write(pfd[1], &m, sizeof(m));

            close(pfd[1]);
            _exit(0);
        }

    }

    write(pfd[1], &m, sizeof(m));

    close(pfd[1]);

    Minfo res;
    while(read(pfd[0], &res, sizeof(res)) > 0) {
        vector[res.line_nr] = res.ocur_nr;
    }

    for(int i=0; i<ROWS; i++) {
        int status;
        wait(&status);
        res = WEXITSTATUS(status);
        if(WIFEXITED(status)) {
            printf("filho terminou\n");
        }

        else {
            perror("filho interrompido");
        }

        close(pfd[0]);
    }

}