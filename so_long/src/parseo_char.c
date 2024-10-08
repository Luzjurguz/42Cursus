/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:47:17 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/05 16:48:00 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	validp(char **mapa)
{
	int	pnj;
	int	y;
	int	x;

	pnj = 0;
	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'P')
				pnj++;
			x++;
		}
		y++;
	}
	if (pnj != 1)
	{
		printf("mapa inválido\n");
		return (-1);
	}
	return (1);
}

int	valide(char **mapa)
{
	int	eh;
	int	y;
	int	x;

	eh = 0;
	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'E')
				eh++;
			x++;
		}
		y++;
	}
	if (eh != 1)
	{
		printf("mapa inválido\n");
		return (-1);
	}
	return (1);
}

int	validc(char **mapa)
{
	int	ce;
	int	y;
	int	x;

	ce = 0;
	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'C')
				ce++;
			x++;
		}
		y++;
	}
	if (ce < 1)
	{
		printf("mapa inválido\n");
		return (-1);
	}
	return (ce);
}

int	validchar(char **mapa)
{
	if (validc(mapa) == -1 || valide(mapa) == -1 || validp(mapa) == -1)
		return (-1);
	return (validc(mapa));
}

int	only(char **mapa)
{
	int	y;
	int	x;

	y = 0;
	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'E' || mapa[y][x] == 'P' || mapa[y][x] == 'C'
				|| mapa[y][x] == '0' || mapa[y][x] == '1')
				x++;
			else
			{
				printf("El mapa contiene carácteres inválidos\n");
				return (1);
			}
		}
		y++;
	}
	return (0);
}
