/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:29:10 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:56:23 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define READ_END 0
# define WRITE_END 1
# define ROJO "\033[0;31m"

# include "../include/libs/get_next_line.h"
# include "../include/libs/ft_printf.h"
# include "../include/libs/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	envario(int fd1, char **env, char *command);
void	ft_print_matrix(char **matrix);
void	son(char *command, char **env, int fd[2], int fd1);
void	daddy(int fd[2]);
char	*ft_path(char *cmdname, char **env);
int		heredoc(char *del);
#endif