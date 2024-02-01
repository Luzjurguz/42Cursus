/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:29:10 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/01/11 13:18:46 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define READ_END 0
# define WRITE_END 1

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
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