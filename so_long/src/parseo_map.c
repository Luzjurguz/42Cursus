/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:44:40 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/08 22:50:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**archivo(int fd)
{
	char	*str;
	char	*str2;
	char	**mapa;

	str2 = get_next_line(fd);
	if (str2 == NULL)
		return (NULL);
	str = NULL;
	while (str2 != NULL)
	{
		str = ft_strjoin(str, str2);
		if (str2)
			free(str2);
		str2 = get_next_line(fd);
	}
	mapa = ft_split(str, '\n');
	if (str)
		free(str);
	return (mapa);
}

int	murosmax(char **mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[y] != NULL)
	{
		if (mapa[y][x] == '1')
			y++;
		else
			return (1);
	}
	y--;
	while (mapa[y][x] != '\0')
	{
		if (mapa[y][x] == '1')
			x++;
		else
			return (1);
	}
	return (0);
}

int	muros(char **mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[y + 1] != NULL)
		y -= -1;
	while (mapa[y][x + 1] != '\0')
		x++;
	while (y >= 0)
	{
		if (mapa[y][x] == '1')
			y--;
		else
			return (1);
	}
	y++;
	while (x > 0)
	{
		if (mapa[y][x] == '1')
			x--;
		else
			return (1);
	}
	return (murosmax(mapa));
}

int	recto(char **mapa)
{
	int	cnt;
	int	ref;
	int	cnt2;

	ref = 0;
	cnt2 = 0;
	cnt = 0;
	while (mapa[0][cnt] != '\0')
		cnt++;
	ref = cnt;
	while (mapa[cnt2] != NULL)
	{
		if (cnt == ref)
		{
			cnt2++;
			cnt = 0;
			while (mapa[cnt2] != NULL && mapa[cnt2][cnt] != '\0')
				cnt++;
		}
		else
			return (printf("El mapa no es rectangular\n"));
	}
	return (0);
}
