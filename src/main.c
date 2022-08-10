/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:19:39 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/09 16:33:12 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>

int main(int argc, char*argv[], char*envp[])
{
	int i = 0;

	while(envp[i])
	{
		printf("%s\n", envp[i]);
	i++;
	}
}	
