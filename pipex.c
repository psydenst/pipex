/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:21:35 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/03 19:07:06 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char *path() // essa função encontra o caminho que é do programa recebido como input
{			// na main.
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

void pipex()
{

}


