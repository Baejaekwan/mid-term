#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	char buffer [BUFSIZ];
	int fd[2];
	if (pipe(fd)==-1){
		perror("pipe error\n");
		exit(0);
	}

	pid_t pid;
	pid = fork();

	if(pid==-1){
		perror("fork error\n");
		exit(0);
	}
	else if(pid==0){
		write(fd[1], "201421258,Baejaekwan",BUFSIZ);
	}
	else {
		read(fd[0], buffer, BUFSIZ);
		printf("My name : %s \n\n", buffer);
	}
	exit(0);
}
