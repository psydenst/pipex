#include <unistd.h>
int main(int argc, char **argv, char **envp) 
{ 
	char *options[3] = {"ls", "-la", NULL}; 
	(void)argc;
	(void)argv; 
	execve("/bin/ls", options, envp); 
	return (0);
}
