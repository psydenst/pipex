/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/18 18:13:54 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char*argv[], char*envp[])
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

	a = 0;
	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
		perror("1ERROR");
	while (paths[a])
	{
		which_path = ft_strjoin_paths(paths[a], '/', command[0]);
		if (access(which_path, F_OK) == 0)
		{
			if (execve(which_path, command, NULL) == -1)
				perror("2ERROR");
		}
		free(which_path);
		a++;
	}
	liberator(command);
	liberator(paths);
	// ERROR in here?
}

void	first_process(int fd[], char*argv[], char*envp[])
{
	int	fdp1;

	fdp1 = open(argv[1], O_RDONLY);
	if (fdp1 < 0)
		perror("3ERROR");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("4ERROR");
	if (dup2(fdp1, STDIN_FILENO) == -1)
		perror("5ERROR");
	close(fd[0]);
	close(fdp1);
	close(fd[1]);
	executer(argv[2], envp);
}

void	second_process(int *fd, char*argv[], char *envp[])
{
	int	fdp2;

	fdp2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fdp2 < 0)
		perror("6ERROR");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("ERROR");
	if (dup2(fdp2, STDOUT_FILENO == -1))
		perror("7ERROR");
	close(fd[1]); // fechando a ponta de escrever
	close(fdp2);
	close(fd[0]); // fechando a porta de ler. 
	executer(argv[3], envp);
}

void	pipex(int argc, char*argv[], char*envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		write(1, "Wrong number of arguments!\n", 28);
	pipe(fd);
	if (pipe(fd) == -1)
		perror("8ERROR");
	pid1 = fork();
	if (pid1 == -1)
		perror("9ERROR");
	else if (pid1 == 0)
		first_process(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		perror("10ERROR");
	else if (pid2 == 0)
		second_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
