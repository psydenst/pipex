/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/09 20:14:12 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


int main(int argc, char*argv[], char*envp[])
{
	pipex(argc, argv, envp);
	return (0);
}

void	first_process(int fd, char*argv[], char* envp[])
{
	int fdp1;


// this function should apply open into the argv[1], first file, then
// it should atribute the fd of argv[1] to a variable. We duplicate fd[1] and pass the
// standard output to it
// then, We duplicate fdp1 and pass the stdinput to it;  
// Por fim, passamos para a função execute o cmd1 argv[2] envp
}

void	second_process(int fd, char*argv[], char*envp[])
{
// 
}



void	pipex(int argc, char*argv[], char*envp[])
{
	int	fd[2];
	int pid1; // process identifier
	int pid2;

	if(argc != 5)
		write(1, "Wrong number of arguments!", 27);
	pipe(fd);
	if (pipe(fd) == -1) // pipe return -1 when error 
		perror("Error: ");

	pid1 = fork();
	if (pid1 == -1)
		perror("Error: ");
	if(pid1 == 0)
		first_process(fd, argv, envp);
	pid2 = fork();
	if(pid2 == -1)
		perror("Error: ");
	if(pid2 == 0)
		second_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

/* LOGICS  

char *path() // essa função encontra o caminho que é do programa recebido como input  na main.
{
	

}	


void	exec () // essa função executa propriamente o programa. Aqui usamos o comando
{				// execve, que vem da unistd.h .  
}

int acess (const char *pathname, int mode) // nessa função, usamos strjoin para juntar  
{
	// if mode F_OK, diz que o comando existe na pasta. 
	// if mode X_OK, ok para executar ele. 
	// essa função retornará 0  em caso de F_OK e X_OK e, caso contrário, -1.
}

pid_t fork(void)
{
	// aqui vamos criar um child process. Nesse processo, nós vamos 
	// aqui dentro, é preciso finalizar o child process na marra com a função wait(). 
}

*/
