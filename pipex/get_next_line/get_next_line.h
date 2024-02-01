/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:56:50 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/01/11 14:09:29 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoint2(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*read_save(char *stack, int fd);
char	*copy_in_line(char *stack);
char	*update_stack(char *stack);
char	*ft_strchr(const char *str, int c);
#endif