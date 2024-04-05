#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "person.h"

// chmod +x pscript.sh
// ./psctipt 1000 (1000 = nºpessoas)

int main(int argc, char* argv[]){

    if ( argc < 3 )
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if ( strcmp(argv[1],"-i") == 0 )
    {
        add_person(argv[2], atoi(argv[3]));
    }

    if ( strcmp(argv[1],"-l") == 0 )
    {
        list_persons(atoi(argv[2]));
    }

    if ( strcmp(argv[1],"-u") == 0 )
    {

        clock_t start_time, end_time;
        double total_time;

        start_time = clock();

        change_agev1(argv[2], atoi(argv[3]));

        end_time = clock();

        total_time = ((double)(end_time - start_time)) * 1000 / CLOCKS_PER_SEC;

        printf("change_agev1: demorou %.6f milissegundos para executar\n", total_time);
    }

    if ( strcmp(argv[1],"-o") == 0 )
    {

        clock_t start_time, end_time;
        double total_time;

        start_time = clock();

        change_agev2(atol(argv[2]), atoi(argv[3]));

        end_time = clock();

        total_time = ((double)(end_time - start_time)) * 1000 / CLOCKS_PER_SEC;

        printf("change_agev2: demorou %.6f milissegundos para executar\n", total_time);
    }

    return 0;
}
