/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/08 21:43:47 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cholo
{
	char		**mapa;
	int			pj_x;
	int			pj_y;
	int			ce;
	int			cecoge;
	int			pas;
	int			an;
	int			al;
	mlx_t		*venti;
	mlx_image_t	*suelo;
	mlx_image_t	*pnj;
	mlx_image_t	*muro;
	mlx_image_t	**colec;
	mlx_image_t	*sal;
}				t_cholo;

void			mov(t_cholo *cholo, int32_t *posy, int32_t *posx, char wasd);
int				sepisa(char **mapa, int32_t posy, int32_t posx, char wasd);
void			hoooook(mlx_key_data_t tecla, void *chostruc);
void			cogecol(t_cholo *cholo);
void			sesale(void *chostruc);
void			textu(t_cholo *cholo);
void			pj(t_cholo *cholo, int cnt, int cnt2);
void			sal(t_cholo *cholo, int cnt, int cnt2);
void			colec(t_cholo *cholo, int cnt, int cnt2);
void			ft_pos(t_cholo *cholo);
char			**fri(char **mapa);
void			boia_ber(char *str);
int				flotfil(char **mapa, int x, int y);
char			**archivo(int fd);
int				murosmax(char **mapa);
int				muros(char **mapa);
int				recto(char **mapa);
int				validp(char **mapa);
int				valide(char **mapa);
int				validc(char **mapa);
int				validchar(char **mapa);
int				only(char **mapa);
void			matalics(void *cholostruc);

#endif