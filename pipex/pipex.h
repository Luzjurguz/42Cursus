/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:29:10 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:45:47 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0
# define WRITE_END 1
# define ROJO "\033[0;31m"

# include "include/libs/libft.h"
# include "include/libs/ft_printf.h"
# include "include/libs/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_print_matrix(char **matrix);
int		son(char **argv, char **env, int pipefd[2]);
void	daddy(char **argv, char **env, int pipefd[2]);
char	*ft_path(char *cmdname, char **env);
#endif