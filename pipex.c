/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/07/22 17:28:07 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
void pipex() // primeiro vamos fazer um pipe e depois popular suas duas pontas. 
{
	int end[2];
	pid_t parent; 

	pipe(end); // temos duas pontas
	parent = fork() // estamos populando as pontas agora
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(f1, cmd1); // child escreve
	else
		parent_process(f2, cmd2) // parent lê 
}

