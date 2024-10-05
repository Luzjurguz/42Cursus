/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimiento.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:57:04 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/05 17:06:13 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mov(t_cholo *cholo, int32_t *posy, int32_t *posx, char wasd)
{
	if (wasd == 'W')
		*posy -= 64;
	if (wasd == 'S')
		*posy += 64;
	if (wasd == 'A')
		*posx -= 64;
	if (wasd == 'D')
		*posx += 64;
	cholo->pas++;
	ft_putstr_fd("pasos: ", 0);
	ft_putnbr_fd(cholo->pas, 0);
	ft_putstr_fd("\n", 0);
}

int	sepisa(char **mapa, int32_t posy, int32_t posx, char wasd)
{
	if (wasd == 'W')
		if (mapa[posy - 1][posx] == '1')
			return (1);
	if (wasd == 'S')
		if (mapa[posy + 1][posx] == '1')
			return (1);
	if (wasd == 'A')
		if (mapa[posy][posx - 1] == '1')
			return (1);
	if (wasd == 'D')
		if (mapa[posy][posx + 1] == '1')
			return (1);
	return (0);
}

void	hoooook(mlx_key_data_t tecla, void *chostruc)
{
	t_cholo	*cholo;
	int32_t	*posx;
	int32_t	*posy;

	cholo = chostruc;
	posx = &cholo->pnj->instances[0].x;
	posy = &cholo->pnj->instances[0].y;
	if (tecla.action == MLX_PRESS)
	{
		if (tecla.key == MLX_KEY_ESCAPE)
			mlx_close_window(cholo->venti);
		if (tecla.key == MLX_KEY_W && !sepisa(cholo->mapa, *posy / 64, *posx
				/ 64, 'W'))
			mov(cholo, posy, posx, 'W');
		if (tecla.key == MLX_KEY_S && !sepisa(cholo->mapa, *posy / 64, *posx
				/ 64, 'S'))
			mov(cholo, posy, posx, 'S');
		if (tecla.key == MLX_KEY_A && !sepisa(cholo->mapa, *posy / 64, *posx
				/ 64, 'A'))
			mov(cholo, posy, posx, 'A');
		if (tecla.key == MLX_KEY_D && !sepisa(cholo->mapa, *posy / 64, *posx
				/ 64, 'D'))
			mov(cholo, posy, posx, 'D');
	}
}

void	cogecol(t_cholo *cholo)
{
	int			x;
	int			y;
	int			cnt;
	static int	flag = 0;

	cnt = 0;
	x = cholo->pnj->instances[0].x / 64;
	y = cholo->pnj->instances[0].y / 64;
	if (cholo->mapa[y][x] == 'C')
	{
		if (cholo->cecoge < cholo->ce && flag == 0)
		{
			while (cholo->colec[cnt]->instances[0].x / 64 != x
				|| cholo->colec[cnt]->instances[0].y / 64 != y)
				cnt++;
			cholo->colec[cnt]->enabled = false;
			cholo->mapa[y][x] = '0';
			cholo->cecoge++;
			flag = 1;
		}
	}
	else
		flag = 0;
}

void	sesale(void *chostruc)
{
	t_cholo	*cholo;

	cholo = chostruc;
	cogecol(cholo);
	if (cholo->cecoge == cholo->ce)
	{
		cholo->sal->enabled = true;
		if (cholo->pnj->instances[0].x == cholo->sal->instances[0].x
			&& cholo->pnj->instances[0].y == cholo->sal->instances[0].y)
		{
			ft_putstr_fd("HAS GANADO!!!!!!!! :D \n", 0);
			exit(0);
		}
	}
}
