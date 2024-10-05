/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:51:27 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/05 18:03:49 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_pos(t_cholo *cholo)
{
	int	x;
	int	y;

	y = 0;
	while (cholo->mapa[y] != NULL)
	{
		x = 0;
		while (cholo->mapa[y][x])
		{
			if (cholo->mapa[y][x] == 'P')
			{
				cholo->pj_x = x;
				cholo->pj_y = y;
			}
			x++;
		}
		cholo->an = x;
		y++;
	}
	cholo->al = y;
}

char	**fri(char **mapa)
{
	int	cnt;

	cnt = 0;
	if (mapa)
	{
		while (mapa[cnt])
		{
			free(mapa[cnt]);
			cnt++;
		}
		free(mapa);
	}
	return (NULL);
}

void	boia_ber(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '.' && str[cnt] != '\0')
		cnt++;
	if (str[cnt] == '.' && str[cnt + 1] != '\0')
	{
		cnt++;
		if (str[cnt] == 'b' && str[cnt + 1] != '\0')
			cnt++;
		if (str[cnt] == 'e' && str[cnt + 1] != '\0')
			cnt++;
		if (str[cnt] == 'r')
			cnt++;
		if (str[cnt] == '\0')
			return ;
	}
	printf("[ERROR] ERROR EXTENSIÓN!!\n");
	exit(1);
}

int	flotfil(char **mapa, int x, int y)
{
	int	cnt;

	cnt = 0;
	if (mapa[y][x] != '1' && mapa[y][x] != 'H')
	{
		if (mapa[y][x] == 'C')
			cnt++;
		if (mapa[y][x] == 'E')
			cnt++;
		mapa[y][x] = 'H';
		cnt += flotfil(mapa, x + 1, y);
		cnt += flotfil(mapa, x, y + 1);
		cnt += flotfil(mapa, x - 1, y);
		cnt += flotfil(mapa, x, y - 1);
	}
	return (cnt);
}
