/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:56:50 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/11/15 19:45:42 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*read_save(char *stack, int fd);
char	*copy_in_line(char *stack);
char	*update_stack(char *stack);
char	*ft_strchr(const char *str, int c);
#endif