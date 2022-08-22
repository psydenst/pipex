/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/22 20:46:57 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char*argv[], char*env[])
{
	pipex(argc, argv, env);
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
	// int k = 0;
	// while(command[k])
		// printf("Os valores de k são: %s\n", command[k++]);
	paths = splitting_paths(envp);
	if (paths == NULL)
		ft_perror("1ERROR");
	while (paths[a])
	{
		which_path = ft_strjoin_paths(paths[a], '/', command[0]);
		if (access(which_path, F_OK | X_OK) == 0)
		{
			// printf("O valor de which_path é: %s\n", which_path);
			if (execve(which_path, command, NULL) == -1)
				ft_perror("2ERROR");
		}
		free(which_path);
		a++;
	}
	liberator(command);
	liberator(paths);
}

void	first_process(int fd[], char*argv[], char*envp[])
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		ft_perror("3ERROR");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("4ERROR");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_perror("5ERROR");
	close(fd[0]);
	close(fd_in);
	close(fd[1]);
	executer(argv[2], envp);
}

void	second_process(int *fd, char*argv[], char *envp[])
{
	int	fd_out;

	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_out < 0)
		ft_perror("6ERROR");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("54ERROR");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_perror("7ERROR");
	close(fd_out);
	close(fd[1]); // fechando a ponta de escrever
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
	if (pipe(fd) == -1)
		ft_perror("8ERROR");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("9ERROR");
	else if (pid1 == 0)
		first_process(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("10ERROR");
	else if (pid2 == 0)
		second_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
