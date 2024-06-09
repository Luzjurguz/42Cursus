/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cholo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/06/09 04:04:18 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**archivo(int fd)
{
	char	*str;
	char	*str2;
	char	**mapa;

	str2 = get_next_line(fd);
	str = NULL;
	while (str2 != NULL)
	{
		str = ft_strjoin(str, str2);
		str2 = get_next_line(fd);
	}
	mapa = ft_split(str, '\n');
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
int	parse(char **mapa)
{
	int	ce = 0;
	int	eh = 0;
	int	pnj = 0;
	int	y;
	int	x;

	while (mapa[y] != NULL)
	{
		x = 0;
		while (mapa[y][x] != '\0')
		{
			if (mapa[y][x] == 'E')
				eh++;
			if (mapa[y][x] == 'P')
				pnj++;
			if (mapa[y][x] == 'C')
				ce++;
			x++;
		}
		y++;
	}
	if (eh != 1 || ce < 1 || pnj != 1)
	{
 		printf("mapa inválido");
		return(1);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_cholo	*cholo;

	cholo = malloc(sizeof(t_cholo));
	cholo->mapa = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		cholo->mapa = archivo(fd);
		printf("%i\n", muros(cholo->mapa));
		parse(cholo->mapa);
	}
}


// 				mapa[i][cnt] = str[cnt];
// 				cnt++;
// 			}
// 		}
// 		if (eh != 1 || ce < 1 || pnj != 1 || muro != 1)
// 		{
// 			ft_printf("mapa inlválido");
// 			exit;


// void parseo()
// {

// 	if (str)
// 	{
// 		char *str;
// 		char **mapa;
// 		int cnt;
// 		int muro;
// 		int ce;
// 		int eh;
// 		int pnj;
// 		int cuadrado;
// 		int l;
// 		int i;
// 		int x;
// 		int y;
// 		cnt = 0;

// 		while (str[cnt] != '\0')
// 		{
// 			mapa[i][cnt] = str[cnt];
// 			cnt++;
// 			if (str[cnt + 1] == '\0')
// 			{
// 				mapa[i][cnt + 1] = '\0';
// 				cnt = 0;
// 				str = get_next_line("ruta del mapa");
// 			}
// 			if (str == NULL)
// 		}

// 		while (str[cnt] != '\0')
// 		{

// 			if (str[cnt] != "1")
// 			{
// 				ft_printf("mapa inválido");
// 				exit(1);
// 			}
// 			cnt++;
// 		}
// 		mapa[i][cnt + 1] = str[cnt + 1];
// 		i++;
// 		while (str != NULL)
// 		{
// 			str = get_next_line("ruta del mapa");
// 			while (str[cnt] != '\0')
// 			{
// 				if (str[cnt] != "E" && str[cnt] != "P" && str[cnt] != "C"
//&& str[cnt] != "1" && str[cnt] != "0")
// 				{
// 					ft_printf("mapa inválido");
// 					exit;
// 				}
// 				else
// 				{
// 					if (cnt == 0 || str[cnt] + 1 == '\0')
// 					{
// 						if (str[cnt] == "1")
// 							muro = 3;
// 						else
// 						{
// 							ft_printf("mapa inválido");
// 							exit;
// 						}
// 					}
// 					if (str[cnt] == "E")
// 						eh++;
// 					if (str[cnt] == "P")
// 						pnj++;
// 					if (str[cnt] == "C")
// 						ce++;
// 				}
// 				mapa[i][cnt] = str[cnt];
// 				cnt++;
// 			}
// 		}
// 		if (eh != 1 || ce < 1 || pnj != 1 || muro != 1)
// 		{
// 			ft_printf("mapa inlválido");
// 			exit;
// 		}
// 		else
// 			parse(cholo->mapa, cholo->x, cholo->y);
// 	}
// }

// void parse(char **mapa, int x, int y)
// {
// 	if (mapa[y][x] != '1' && mapa[y][x] != 'H')
// 	{
// 		mapa[y][x] = 'H';
// 		parse(mapa, x + 1, y);
// 		parse(mapa, x, y + 1);
// 		parse(mapa, x - 1, y);
// 		parse(mapa, x, y - 1);
// 	}
// }

// void hook(void *param)
// {
// 	mlx_t *mlx;

// 	mlx = (mlx_t *)param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }

// void shaders()
// {
// }

// int32_t main(void)
// {
// 	mlx_t *mlx;
// 	mlx_texture_t *fondo;
// 	mlx_texture_t *pnj;
// 	mlx_texture_t *malo;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);

// 	fondo = mlx_load_png("fondo.png");
// 	pnj = mlx_load_png("pnj.png");
// 	malo = mlx_load_png("malo.png");

// 	g_img = mlx_texture_to_image(mlx, pnj);

// 	mlx_image_to_window(mlx, g_img, 0, 0);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	// mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }