/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:20:40 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/26 18:25:40 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**splitting_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			paths = ft_split(envp[i] + 5, ':');
		i++;
	}
	return (paths);
}

char	*ft_strjoin_paths(char const *s1, char connector, char const *s2)
{
	char	*p;
	size_t	a;
	size_t	b;

	p = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * (sizeof(char)));
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
	while (a < ft_strlen(s1) + ft_strlen(s2) + 2)
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

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
