#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>

//demo of pipe where parent process writes into pipe and child process reads from same pipe

int main()
{
	int fd[2], cpid = -1, prpid = -1;
	int wbytes, rbytes;

	int pipefd = pipe(fd);

	cpid = fork();
	char str1[] = "child is reading and parent is writing";
	char str2[100];	

	printf("fork pid %d\n", cpid);

	fflush(stdout);

	if(cpid > 0) //parent process
	{
		close(fd[0]);//close reading end of pipe
	        wbytes = write(fd[1], str1, strlen(str1));
		printf("written bytes %d\n", wbytes);
//		waitpid(cpid, NULL, 0);
	}
	else if(cpid == 0) //child process
	{
		close(fd[1]);//close writing end of pipe
                rbytes = read(fd[0], str2, wbytes);
		write(1, str2, rbytes);
		printf("\nread bytes %d \t %s\n", rbytes, str2);
	}
	else if(cpid < 0)
	{
		printf("fork failed\n");
	}

	exit(0);	
//	return 0;
}
