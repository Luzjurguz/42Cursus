/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:10:59 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/07/05 21:25:16 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_contador(char *str)
{
	int	cnt;
	int	i;
	
	cnt = 0;
	i = 0;
	while (str[cnt] != '\0')
	{
		str[cnt]++;
		i++;
	}
	return (i);
}

int	ft_print_char(char c)
{
	int	cnt;
	
	cnt = 0;
	write(1, &c, 1);
	cnt++;
	return (cnt);
}
