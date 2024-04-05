#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void filho_to_pai() {

	int pipefd[2];
	int ret = pipe(pipefd);
	if(ret < 0) {
		perror("Erro a criar pipe");
	}

	pid_t pid = fork();
	switch(pid) {
		case -1:
			perror("erro no fork");

		case 0:
			//filho
			int valor;
			close(pipefd[0]);

			for(valor=0; valor<10000; valor++) {
				printf("a escrever %d\n", valor);
				write(pipefd[1], &valor, sizeof(int));
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

void pai_to_filho() {

	int pipefd[2];
	int ret = pipe(pipefd);
	if(ret < 0) {
		perror("Erro a criar pipe");
	}

	pid_t pid = fork();
	switch(pid) {
		case -1:
			perror("erro no fork");

		case 0:
			//filho
			int res;
			close(pipefd[1]);

			read(pipefd[0], &res, sizeof(int));
			close(pipefd[0]);
			printf("filho: recebi %d\n", res);

			_exit(0);

		default:
			//pai
			int valor = 10;
			close(pipefd[0]);

			write(pipefd[1], &valor, sizeof(int));
			close(pipefd[1]);

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

int main() {

	//pai_to_filho();
	filho_to_pai();

	return 0;
}