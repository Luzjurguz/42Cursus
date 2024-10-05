/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lics.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:05:00 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/05 18:12:23 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void matalics(void *cholostruc)
{
	t_cholo *cholo;
	int cnt;
	
	cnt = 0;
	cholo = cholostruc;
	cholo->mapa = fri(cholo->mapa);
	free(cholo->venti);
	free(cholo->suelo);
	free(cholo->pnj);
	free(cholo->muro);
	free(cholo->sal);
	while(cholo->colec[cnt])
	{
		free(cholo->colec[cnt]);
		cnt++;
	}
	free(cholo->colec);
	free(cholo);
}
