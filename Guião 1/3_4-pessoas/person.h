#define FILENAME "file_pessoas"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct person {
	char name[100];
	int age;
}Person;

int add_person(char* name, int age);

int list_persons(int nr);

int change_agev1(char* name, int new_age);

// Mudar idade em posição, usando lseeks
int change_agev2(long pos, int new_age);