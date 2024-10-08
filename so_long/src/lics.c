/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lics.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:05:00 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/08 22:36:44 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	matalics(void *cholostruc)
{
	t_cholo	*cholo;
	int		cnt;

	cnt = 0;
	cholo = cholostruc;
	cholo->mapa = fri(cholo->mapa);
	mlx_delete_image(cholo->venti, cholo->suelo);
	mlx_delete_image(cholo->venti, cholo->pnj);
	mlx_delete_image(cholo->venti, cholo->muro);
	mlx_delete_image(cholo->venti, cholo->sal);
	while (cnt < cholo->ce - 1)
	{
		mlx_delete_image(cholo->venti, cholo->colec[cnt]);
		cnt++;
	}
	free(cholo->colec);
	free(cholo->venti);
	free(cholo);
}
