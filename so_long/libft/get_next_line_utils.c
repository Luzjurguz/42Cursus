/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:56:58 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/11/15 21:05:57 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(len * (sizeof(char)) + 1);
	if (!s2)
	{
		return (0);
	}
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *str, int c)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (NULL);
	while (str[cnt] != '\0' && str[cnt] != (char)c)
		cnt++;
	if (str[cnt] == (char)c)
	{
		return ((char *)&str[cnt]);
	}
	return (0);
}
