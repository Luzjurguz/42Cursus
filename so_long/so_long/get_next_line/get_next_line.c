/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:56:11 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/12/11 20:54:09 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_save(char *stack, int fd)
{
	char	*s;
	int		cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!s)
			return (NULL);
		cnt = 1;
		while (cnt > 0 && !ft_strchr(stack, '\n'))
		{
			cnt = read(fd, s, BUFFER_SIZE);
			if (cnt < 0)
			{
				return (free(stack), free(s), NULL);
			}
			s[cnt] = '\0';
			stack = ft_strjoin2(stack, s);
		}
		free(s);
	}
	return (stack);
}

char	*copy_in_line(char *stack)
{
	char	*line;
	int		cnt;

	cnt = 0;
	if (stack[0] == '\0')
		return (NULL);
	while (stack[cnt] != '\n' && stack[cnt])
		cnt++;
	line = (char *)malloc(sizeof(char) * (cnt + 2));
	if (!line)
		return (NULL);
	cnt = 0;
	while (stack[cnt] && stack[cnt] != '\n')
	{
		line[cnt] = stack[cnt];
		cnt++;
	}
	if (stack[cnt] == '\n')
		line[cnt++] = '\n';
	line[cnt] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	int		cnt;
	char	*stack2;

	cnt = 0;
	while (stack[cnt] && stack[cnt] != '\n')
	{
		cnt++;
	}
	if (stack[cnt] == '\0')
		return (free(stack), NULL);
	stack2 = ft_strdup(stack + cnt + (stack[cnt] == '\n'));
	free(stack);
	return (stack2);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	stack = read_save(stack, fd);
	if (stack == NULL)
		return (NULL);
	line = copy_in_line(stack);
	stack = update_stack(stack);
	return (line);
}
