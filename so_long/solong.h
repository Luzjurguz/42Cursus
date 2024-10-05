/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/10/03 12:48:35 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
    # define SOLONG_H

    #include "MLX42/include/MLX42/MLX42.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <memory.h>
    #include <fcntl.h>
    #include "libft/libft.h"

typedef struct s_cholo
{
    char **mapa;
    int pj_x;
    int pj_y;
    int ce;
    int cecoge;
    int pas;
    int an;
    int al;
    mlx_t *venti;
    mlx_image_t *suelo;
    mlx_image_t *pnj;
    mlx_image_t *muro;
    mlx_image_t **colec;
    mlx_image_t  *sal;
} t_cholo;

#endif