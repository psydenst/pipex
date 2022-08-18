/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:20:40 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/18 19:07:45 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**splitting_paths(char *envp[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i], ':')); // I think that it should have a + 5 here. 
		if (envp[i][(j + 1)] == '\0')
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (0);
}

char	*ft_strjoin_paths(char const *s1, char connector, char const *s2)
{
	char	*p;
	size_t	a;
	size_t	b;

	p = malloc((ft_strlen(s1) + ft_strlen(s2)) * (sizeof(char *)));
	if (p == 0)
		return (NULL);
	a = 0;
	b = 0;
	while (a < ft_strlen(s1))
	{
		p[a] = s1[a];
		a++;
	}
	p[a++] = connector;
	while (a < ft_strlen(s1) + ft_strlen(s2))
	{
		p[a] = s2[b];
		a++;
		b++;
	}
	p[a] = '\0';
	return (p);
}

void	liberator(char **freeing)
{
	int	i;

	i = 0;
	while (freeing[i])
	{
		free(freeing[i]);
		i++;
	}
	free(freeing);
}
