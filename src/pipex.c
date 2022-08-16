/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/16 19:29:00 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int argc, char*argv[], char*envp[])
{
	pipex(argc, argv, envp);
	return (0);
}

void	executer(char *cmd, char *envp[])
{
	int		a;
	char	**command;
	char	**paths;
	char	*which_path;
	
	command = ft_split(cmd, ' '); 
	printf("%s\n", command[0]);
		// paths = splitting_paths(envp); I still need to create this function in utils.c 
	/*
	if (paths == NULL)
		perror("Error: no path"); */
	while(paths[a])
	{
		which_path = ft_strjoin_path(paths[a], '/', command[a]);
		if (access(which_path, (F_OK | X_OK) == 0)) // X_OK
		{
			if (execve(which_path, command, NULL) == -1)
				perror("ERROR");
		}
		free(which_path);
		a++;
	}
}

void	first_process(int fd[], char*argv[], char*envp[])
{
	int fdp1;
	
	fdp1 = open(argv[1], O_RDONLY);
	if (fdp1 < 0)
		perror("Error");
	if(dup2(fd[1], STDOUT_FILENO) == -1)
		perror("ERROR");
	if(dup2(fdp1, STDIN_FILENO) == -1)
		perror("ERROR");
	close(fd[0]);
	close(fdp1);
	close(fd[1]);
	executer(argv[2], envp);

// this function should apply open into the argv[1], first file, then
// it should atribute the fd of argv[1] to a variable. We duplicate fd[1] and pass the
// standard output to it
// then, We duplicate fdp1 and pass the stdinput to it;  
// Por fim, passamos para a função execute o cmd1 argv[2] envp
}

void	second_process(int *fd, char*argv[], char*envp[])
{
	int fdp2;

	close(fd[1]);
	fdp2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fdp2 < 0)
		perror("ERROR");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("ERROR");
	if (dup2(fdp2, STDOUT_FILENO == -1))
		perror("ERROR");
	close(fd[0]);

// this function should apply open into the argv[1], first file, then
// it should atribute the fd of argv[1] to a variable. We duplicate fd[1] and pass the
// standard output to it
// then, We duplicate fdp1 and pass the stdinput to it;  
// Por fim, passamos para a função execute o cmd2 argv[4] envp
}



void	pipex(int argc, char*argv[], char*envp[])
{
	int	fd[2]; // int *fd[arc - 3]
			   // int **fd
			   // fd = malloc(sizeof(int *) argc - 3
			   // int counter = 0;
			   // while (i < argc - 3)
			   // {
			   // fd[i] = malloc(sizeof(int) * 2)
			   //
			   //	fd[0][2] [2] -> [0 ou 1]
			   //	fd[1][2] 
			   //
			   //	close(fd[0][0]
			   //
			   //	close(fd[1][1]
			   //	close(fd[2][0]
			   //
			   //	dup2(fd[1][0], STDIN_FILEN0)
			   //	dup2(fd[2][1], 1)
			   //
			   //
	int pid1; // process identifier
	int pid2;

	if(argc != 5)
		write(1, "Wrong number of arguments!\n", 28);
	pipe(fd);
	if (pipe(fd) == -1) // pipe return -1 when error 
		perror("Error: ");

	pid1 = fork();
	if (pid1 == -1)
		perror("Error: ");
	else if(pid1 == 0)
		first_process(fd, argv, envp);
	pid2 = fork();
	if(pid2 == -1)
		perror("Error: ");
	else if(pid2 == 0)
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
