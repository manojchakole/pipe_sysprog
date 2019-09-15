#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int pfd1[2], pfd2[2], wbytes1, rbytes1, wbytes2, rbytes2;
	int cpid, prpid;

//        cpid = fork();
//	printf("pipe after fork\n");

	int pd1 = pipe(pfd1);
	int pd2 = pipe(pfd2);

        printf("pipe before fork\n");
        cpid = fork();

	char wstr1[] = "Parent: this is bidirectional pipe demo!--";
	char wstr2[] = "Child: Yes I'm getting!";
	char rstr1[50], rstr2[50];

	fflush(stdout);

//	printf("\nfork pid %d\n", cpid);

	if(cpid > 0)//parent process
	{
//	        printf("\nParent: fork pid %d\n", cpid);

		close(pfd2[0]);
//		close(pfd1[0]);
		close(pfd1[1]);
				
		wbytes1 = write(pfd2[1], wstr1, strlen(wstr1));

		rbytes1 = read(pfd1[0], rstr1, strlen(wstr2));

//		printf("\nParent: written bytes %d\t read bytes %d\n", wbytes1, rbytes1);
//	        fflush(stdout);
		write(1, rstr1, rbytes1);	
	}
	else if(cpid == 0)//child process
	{
//	        printf("\nChild: fork pid %d\n", cpid);

		close(pfd1[0]);
//		close(pfd2[0]);
		close(pfd2[1]);	
 
	        wbytes2 = write(pfd1[1], wstr2, strlen(wstr2));

                rbytes2 = read(pfd2[0], rstr2, strlen(wstr1));

                write(1, rstr2, rbytes2);

//                printf("\nChild: written bytes %d\t read bytes %d\n", wbytes2, rbytes2);
//	        fflush(stdout);
//		write(1, rstr2, rbytes2);
	}

	return 0;
}
