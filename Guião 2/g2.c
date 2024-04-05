#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	pid_t pid = fork();
	int i = 10;

	// processo filho
	if(pid==0) {
		i++;
		printf("FILHO: i %d\n", i);
		printf("FILHO: o meu pid: %d\n", getpid());
		printf("FILHO: pid do meu pai: %d\n", getppid());
		//printf("FILHO: retorno fork %d\n", pid);
		_exit(-1); // para terminar com valor 0 ou -1 (não usar return 0 em forks!)
	}

	// processo pai
	else {
		i--;
		printf("PAI: i %d\n", i);
		printf("PAI: o meu pid: %d\n", getpid());
		printf("PAI: pid do meu pai: %d\n", getppid());
		//printf("PAI: retorno fork %d\n", pid);		

		int status;
		pid_t wait_pid = wait(&status); // espera que o processo filho termine

		printf("wait_pid %d\n", wait_pid); // filho qual o pai esperou que terminasse

		if(WIFEXITED(status)) { // terminou corretamente ou não
			printf("Valor exit filho: %d\n", WEXITSTATUS(status));
		}

		else {
			printf("Erro ao terminar\n");
		}
	}

	return 0;
}