///////////
//GUIÃO 1//
///////////

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */

#define BUFFER_SIZE 4096

/*
Chamadas ao sistema:

int open(const char *path, int oflag [, mode]);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
off_t lseek(int fd, off_t offset, int whence);
int close(int fildes);
*/

/*
1. Implemente em C um programa mycat com funcionalidade similar ao comando cat, que lˆe do seu
stdin e escreve para o seu stdout.
*/

int mycat() {
	// buffer com 1024 bytes para guardar
	char buffer[BUFFER_SIZE];
	ssize_t res_read;

	// stdin = 0 , stdout = 1
	while((res_read = read(0, buffer, BUFFER_SIZE)) > 0) {

		ssize_t res_write = write(1, buffer, res_read);

		if(res_read != res_write) {
			return 1;
		}
	}

	write(2, "fim", 3);

	return 0;

}

/*
2. Implemente em C um programa mycp com funcionalidade similar ao comando cp. Varie o tamanho do
buffer usado e meçaa o tempo necessário para copiar um ficheiro de grande dimensão.
*/

int mycp(char* origem, char* destino) {
	// buffer com 1024 bytes para guardar
	char buffer[BUFFER_SIZE];
	ssize_t res_read;

	int fd_origem = open(origem, O_RDONLY);
	int fd_destino = open(destino, O_WRONLY | O_CREAT, 0640);
	// se funciona retorna 0
	if(fd_destino<0) {
		perror("erro");
	}

	// stdin = 0 , stdout = 1
	while((res_read = read(fd_origem, buffer, BUFFER_SIZE)) > 0) {

		ssize_t res_write = write(fd_destino, buffer, res_read);

		if(res_read != res_write) {
			return 1;
		}
	}

	close(fd_origem);
	close(fd_destino);

	return 0;
}

int main(int argc, char* argv[]) {
	
	return mycp(argv[1], argv[2]);
}

