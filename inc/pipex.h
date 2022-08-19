/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:11:28 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/18 16:34:00 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include "../inc/ft_printf/libft/libft.h"
#include "../inc/ft_printf/libftprintf.h"

void	pipex(int argc, char*argv[], char*envp[]);
void	executer(char *cmd, char*envp[]);
void	first_process(int *fd, char *argv[], char *envp[]);
void	second_process(int *fd, char *argv[], char *envp[]);
char	**splitting_paths(char *envp[]);
char	*ft_strjoin_paths(char const *s1, char connector, char const *s2);
void	liberator(char **freeing);
#endif
