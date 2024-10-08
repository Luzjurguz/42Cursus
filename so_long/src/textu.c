/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:55:00 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/08 22:44:34 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	textu(t_cholo *cholo)
{
	mlx_texture_t	*textu;
	int				cnt;

	textu = mlx_load_png("textu/suelo.png");
	cholo->suelo = mlx_texture_to_image(cholo->venti, textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/pj.png");
	cholo->pnj = mlx_texture_to_image(cholo->venti, textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/muro.png");
	cholo->muro = mlx_texture_to_image(cholo->venti, textu);
	mlx_delete_texture(textu);
	textu = mlx_load_png("textu/sal.png");
	cholo->sal = mlx_texture_to_image(cholo->venti, textu);
	mlx_delete_texture(textu);
	cnt = 0;
	cholo->colec = malloc(sizeof(mlx_image_t) * (cholo->ce + 1));
	while (cnt < cholo->ce)
	{
		textu = mlx_load_png("textu/colec.png");
		cholo->colec[cnt] = mlx_texture_to_image(cholo->venti, textu);
		mlx_delete_texture(textu);
		cnt++;
	}
}

void	pj(t_cholo *cholo, int cnt, int cnt2)
{
	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt * 64);
	mlx_image_to_window(cholo->venti, cholo->pnj, cnt2 * 64, cnt * 64);
}

void	sal(t_cholo *cholo, int cnt, int cnt2)
{
	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt * 64);
	mlx_image_to_window(cholo->venti, cholo->sal, cnt2 * 64, cnt * 64);
	cholo->sal->enabled = false;
}

void	colec(t_cholo *cholo, int cnt, int cnt2)
{
	static int	cnt3 = 0;

	mlx_image_to_window(cholo->venti, cholo->suelo, cnt2 * 64, cnt * 64);
	cholo->cecoge = 0;
	if (cnt3 < cholo->ce)
	{
		mlx_image_to_window(cholo->venti, cholo->colec[cnt3], cnt2 * 64, cnt
			* 64);
		cnt3++;
	}
}
