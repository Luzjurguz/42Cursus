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
	
	open()

}
void	hook(void *param)
{
	mlx_t	*mlx;

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

int32_t	main(void)
{
	mlx_t	*mlx;
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