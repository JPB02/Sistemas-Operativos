#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

	printf("bla\n");

	// o exec substitui tudo do programa, 
	// então o printf de baixo não vai ser executado

	char* arr[3] = {"ls", "-l", NULL};

	// int ret = execlp("ls", "ls", "-l", NULL);
	// int ret = execl("/bin/ls", "ls", "-l", NULL);

	// o execvp recebe um array de argumentos, também temos o execv
	int ret = execvp("ls", arr);
	if(ret==-1) {
		perror("erro exec");
	}

	printf("%s\n", argv[0]);

	return 0;
	
}