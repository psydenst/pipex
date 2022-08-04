#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) 
{
   	pid_t pid; 
	pid_t res; 
	int status; 
	pid = fork(); 
	if (pid == -1) 
		return (1); 
	if (pid == 0) 
	{ 
		usleep(50000); 
		printf("Child 1 : I'm the first child !\n"); 
		return (0); 
	} 
	else if (pid > 0) 
	{ 
		pid = fork(); 
		if (pid == -1) 
			return (1); 
		else if(pid == 0) 
		{ 
			usleep(49900); 
			printf("Child 2 : I'm the second child...\n"); 
			return (2); 
		} 
		else if(pid > 0) 
		{ 
			printf("Parent : I have two children !\n"); 
			res = wait(&status);
		   	printf("Parent : I received my child %d\n", res); 
			if (WIFEXITED(status)) // WIFEXTIED só é verdadeiro (1) quando o child process termina. 
				printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status)); // WEXISTATUS dá o PID do child process.  
			else printf("Parent : It was interrupted...\n"); 
			res = wait(&status);
		   	printf("Parent : I received my child %d\n", res); 
			if (WIFEXITED(status)) 
				printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status)); 
			else 
				printf("Parent : It was interrupted...\n"); 
		} 
	} 
	return (0); 
}


/*
int main(void) 
{ 
	pid_t pid; 
	printf("Fork here.\n"); 
	pid = fork(); 
	if (pid == -1) 
	{ 
		// If fork returns -1, there was an error! 
		 return (1);
   	} 
	 printf("\nFork successful!\n"); 
	 if (pid == 0) 
	 { // Fork's return value is 0: // we are now in the child process 
	 	printf("Child: I'm the child, my internal pid is %d.\n", pid);
	 }
	 else if (pid > 0) 
	 { // Fork's return value is not 0 // which means we are in the parent process 
	   printf("Parent: I'm the parent, my child's pid is %d.\n", pid); 
	 }
	 return(0);
}
*/
