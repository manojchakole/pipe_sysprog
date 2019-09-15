#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

// customized pipe demo for two commands

int main()
{
	int pfd[2];

	int pst = pipe(pfd);
	int cpid = fork();
	char readbuff[50], writebuff[] = "Hello, India";

	if(cpid > 0)
	{
		dup2(pfd[1], 1);
		close(pfd[0]);
//		read(pfd[0], readbuff, 50);
//		execlp("cat", "catxyz", "abc", NULL);
                execlp("cat", "catxyz", "abc", NULL);
//                execl("cat", "cat", "abc", (char*)0);
		exit(0);
	}
	else
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
//		write(pfd[1], writebuff, strlen(writebuff));
//		execlp("wc", "wcxyz", NULL);
                execlp("grep", "wcxyz", "d", NULL);
//                execl("wc", "wc", (char*)0);
		exit(0);
	}

	return 0;
}
