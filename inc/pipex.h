/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:11:28 by psydenst          #+#    #+#             */
/*   Updated: 2022/08/09 20:14:15 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

void	pipex(int argc, char*argv[], char*envp[]);
void	executer(char *cmd, char*envp[]);
void	first_process(int fd[], char*argv[], char*envp[]);


#endif
