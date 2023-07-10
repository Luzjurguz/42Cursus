/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:24:46 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/07/05 20:57:37 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_decimal_int(int n)
{
	int	i;
	int	cnt;
	
	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (cnt);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		cnt += ft_print_decimal_int(n / 10);
		ft_print_decimal_int(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
	}
	return (cnt);
}
