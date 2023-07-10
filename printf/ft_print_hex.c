/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:54:43 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/07/05 21:09:53 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex(long unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 16)
	{
		cnt += ft_print_hex(n / 16);
		ft_print_hex(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	return (cnt);
}
