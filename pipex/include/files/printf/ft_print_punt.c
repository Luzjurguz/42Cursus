/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:25:57 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:50:26 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_print_ppunt(long unsigned int n)
{
	return (write(1, "0x", 2) + ft_print_punt(n));
}

int	ft_print_punt(long unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n > 15)
	{
		cnt += ft_print_punt(n / 16);
		cnt += ft_print_punt(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
		cnt++;
	}
	return (cnt);
}
