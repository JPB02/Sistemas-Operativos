#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	pid_t pid = fork();
	switch(pid) {
		case -1:
			perror("erro no fork");
			break;

		case 0: {
			int ret = execlp("ls", "ls", "-l", NULL);
			break;
		}

		// espera que o filho acabe
		default: {
			int status;
			wait(&status);

			if(WIFEXITED(status)) {
				printf("%d\n", WEXITSTATUS(status));
			}

			else {
				perror("filho interrompido");
			}

			break;
		}

	}

	return 0;

}