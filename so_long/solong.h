/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:15:47 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/06/05 23:47:42 by luz-mjur         ###   ########.fr       */
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

    #define WIDTH 720
    #define HEIGHT 720

typedef struct s_cholo
{
    char **mapa;
} t_cholo;

#endif