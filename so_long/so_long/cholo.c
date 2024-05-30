/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/05/09 12:09:21 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parseo()
{
	char *str;
	char **mapa;
	int cnt;
	int muro;
	int ce;
	int eh;
	int pnj;
	int cuadrado;
	int l;
	int i;
	int x;
	int y;

	i = 0;

	while (str)
	{
		cnt = 0;
		str = get_next_line("ruta del mapa"); // primera y ultima llamada todo debe ser 1 //si no hay una siguiente linea todo debe ser 1
		i++;
		while (str[cnt] != '\0')
		{
			mapa[i][cnt] = str[cnt];
			if (str[cnt] != "1")
			{
				ft_printf("mapa inválido");
				exit;
			}
			cnt++;
		}
		str = get_next_line("ruta del mapa");
		while (str[cnt] != '\0')
		{
			if (str[cnt + 1] == '\0')
				if (str[cnt] != "E" & str[cnt] != "P" & str[cnt] != "C" & str[cnt] != "1" & str[cnt] != "0")
				{
					ft_printf("mapa ilválido");
					exit;
				}
				else
				{
					if (cnt == 0 || cnt + 1 == '\0')
					{
						if (str[cnt] == "1")
							muro = 3;
						else
						{
							ft_printf("mapa inválido");
							exit;
						}
					}
					if (str[cnt] == "E")
						eh++;
					if (str[cnt] == "P")
						pnj++;
					if (str[cnt] == "C")
						ce++;
				}
			cnt++;
		}
		if (eh != 1 || ce < 1 || pnj != 1 || muro != 1)
		{
			ft_printf("mapa inlválido");
			exit;
		}
		else
			parse(mapa, x, y);
	}

	void parse(char **mapa, int x, int y)
	{
		if(mapa[x][y])
		{
			if(mapa[x][y] == "0")
				mapa[x][y] == "x";
			else()
			if(map[x][y] != '\0')
				map(mapa, x + 1, y + 1);
		}
	}

	void mapx(char **mapa, int x, int y)
	{
		if (mapa[x][y] != '\0')
		{
			map(mapa, x + 1, y);
		}
	}

	void mapy(char **mapa, int x, int y)
	{
		if (mapa[x][y] != '\0')
		{
			map(mapa, x, y + 1);
		}
	}

	void hook(void *param)
	{
		mlx_t *mlx;

		mlx = (mlx_t *)param;
		if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
			mlx_close_window(mlx);
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			g_img->instances[0].y -= 5;
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			g_img->instances[0].y += 5;
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			g_img->instances[0].x -= 5;
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			g_img->instances[0].x += 5;
	}

	void shaders()
	{
	}

	int32_t main(void)
	{
		mlx_t *mlx;
		mlx_texture_t *fondo;
		mlx_texture_t *pnj;
		mlx_texture_t *malo;

		mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
		if (!mlx)
			exit(EXIT_FAILURE);

		fondo = mlx_load_png("fondo.png");
		pnj = mlx_load_png("pnj.png");
		malo = mlx_load_png("malo.png");

		g_img = mlx_texture_to_image(mlx, pnj);

		mlx_image_to_window(mlx, g_img, 0, 0);
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		// mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}