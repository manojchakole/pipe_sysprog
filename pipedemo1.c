#include<unistd.h>
#include<stdio.h>

//demo for creating pipe, writing some data in it and reading from other end

int main()
{
	int fd[2], cpid, prpid;

	int pfd = pipe(fd);

	if(pfd < 0)
	{
		printf("Failed to create pipe\n");
	}

	char str1[] = "this is new pipe creation !---";
	char str2[50];
	int wbytes = write(fd[1], str1, strlen(str1));
	int rbytes = read(fd[0], str2, wbytes);

	write(1, str2, rbytes);
	close(fd[0]);
	close(fd[1]);

	return 0;
}
