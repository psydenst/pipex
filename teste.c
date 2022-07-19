/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/07/19 19:35:42 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// testando a função exec, pipe, fork, dup2
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
	// estamos imitando a linha de comando "ping google.com | grep 42"
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}

	int pid1 = fork();
	if(pid1 < 0)
	{
		return 2;
	}

	if(pid1 == 0)
	{
		//child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	
	int pid2 = fork;
	if(pid2 < 0)
		return 3;
	
	if (pid2 == 0) 
	{
	// Child process 2 (grep)
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execlp("grep", "grep", "rtt", NULL);
	}

	waitpid(pid1, NULL, 0);
	return (0);
}

