/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:20:40 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/16 20:32:28 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**splitting_paths(char *envp[])
{
	//Basically, we will search for PATH in the four first digit, then we wil return a split in it with ft_split, using : as 
	// a delimeter. 
	int i;
	int j;

	i = 0;
	j = 0;

	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5 ) == 0)
			return(ft_split(envp[i], ':'));
		if(envp[i][(j + 1)] == '\0')
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (0);
}

char	*ft_strjoin_path(char const *s1, char connector, char const *s2)
{
// this function will join both commands received as arguments.
	return (NULL);
}

void	liberator(char **freeing)
{
	// this function will free all the allocated memory. since we are woring with a **, we need to be very caurefull with it. 
} 

int main()
{
	char envp[0][9] = "envevne";
	char envp[1][33] = "PATH=psydenst:psydenst:psydenst";
	
	int i = 0;
	char **result = splitting_paths(envp);
	
	while(i < 10)
	{
	printf("%s\n", result[i]);
	i++;
	}
}
