/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cholo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/05 18:06:06 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	venticarglass(t_cholo *cholo, char **mapa)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (mapa[cnt])
	{
		cnt2 = 0;
		while (mapa[cnt][cnt2])
		{
			if (mapa[cnt][cnt2] == 'P')
				pj(cholo, cnt, cnt2);
			cnt2++;
		}
		cnt++;
	}
}

void	venticar(t_cholo *cholo, char **mapa)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (mapa[cnt])
	{
		cnt2 = 0;
		while (mapa[cnt][cnt2])
		{
			if (mapa[cnt][cnt2] == '0')
				mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt
					* 64);
			if (mapa[cnt][cnt2] == '1')
				mlx_image_to_window(cholo->venti, cholo->muro, cnt2 * 64, cnt
					* 64);
			if (mapa[cnt][cnt2] == 'E')
				sal(cholo, cnt, cnt2);
			if (mapa[cnt][cnt2] == 'C')
				colec(cholo, cnt, cnt2);
			cnt2++;
		}
		cnt++;
	}
	venticarglass(cholo, mapa);
}

int	parseo(char **argv, int fd, t_cholo *cholo)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("No hay acceso al archivo\n");
		return (1);
	}
	cholo->mapa = archivo(fd);
	if (cholo->mapa == NULL)
	{
		printf("El mapa está vacío\n");
		return (1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (muros(cholo->mapa) == 1)
	{
		printf("El mapa no está rodeados por muros\n");
		return (1);
	}
	if (recto(cholo->mapa))
		return (1);
	cholo->ce = validchar(cholo->mapa);
	if (cholo->ce == -1)
		return (1);
	return (0);
}

int	parseo2(t_cholo *cholo)
{
	if (only(cholo->mapa) == 1)
		return (1);
	ft_pos(cholo);
	if (flotfil(cholo->mapa, cholo->pj_x, cholo->pj_y) != cholo->ce + 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_cholo	*cholo;

	cholo = malloc(sizeof(t_cholo));
	fd = 0;
	if (argc == 2)
	{
		boia_ber(argv[1]);
		if (parseo(argv, fd, cholo) == 1)
			return (1);
		if (parseo2(cholo) == 1)
			return (1);
		fd = open(argv[1], O_RDONLY);
		cholo->mapa = fri(cholo->mapa);
		cholo->mapa = archivo(fd);
		cholo->venti = mlx_init(cholo->an * 64, cholo->al * 64,
				"Cholo Simepone", false);
		textu(cholo);
		venticar(cholo, cholo->mapa);
		mlx_key_hook(cholo->venti, hoooook, cholo);
		mlx_loop_hook(cholo->venti, sesale, cholo);
		mlx_close_hook(cholo->venti, matalics, cholo);
		mlx_loop(cholo->venti);
	}
}
