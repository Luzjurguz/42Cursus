/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:48:12 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/12 19:46:19 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contador(char const *s, char c)
{
	int	cnt;
	int	b;

	cnt = 0;
	b = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] != c)
		{
			while (s[cnt] && s[cnt] != c)
				cnt++;
			b++;
		}
		else
			cnt++;
	}
	return (b);
}

static char	*i_arr(char const *s, char c)
{
	char	*str;
	int		cnt;

	cnt = 0;
	while (s[cnt] != '\0' && s[cnt] != c)
	{
		cnt++;
	}
	str = malloc((cnt + 1) * sizeof(char));
	if (!str)
	{
		return (0);
	}
	cnt = 0;
	while (s[cnt] && s[cnt] != c)
	{
		str[cnt] = s[cnt];
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}

static char	**free_m(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		cnt;

	cnt = ft_contador(s, c);
	arr = malloc((cnt + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (*s && i < cnt)
	{
		while (*s && *s == c)
			s++;
		arr[i] = i_arr(s, c);
		if (!arr[i])
		{
			arr = free_m(arr);
			return (0);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
