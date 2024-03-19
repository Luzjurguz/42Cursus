/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:24:46 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:50:22 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_print_decimal_int(int n)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
		return (ft_min());
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		cnt++;
	}
	if (n > 9)
	{
		cnt += ft_print_decimal_int(n / 10);
		cnt += ft_print_decimal_int(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
		cnt++;
	}
	return (cnt);
}

int	ft_print_u_int(unsigned int n)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (n > 9)
	{
		cnt += ft_print_decimal_int(n / 10);
		cnt += ft_print_decimal_int(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
		cnt++;
	}
	return (cnt);
}
