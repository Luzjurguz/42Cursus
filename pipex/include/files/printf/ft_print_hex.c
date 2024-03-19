/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:54:43 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:50:24 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_print_hex(unsigned int n, char c)
{
	int		cnt;
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEFG";
	cnt = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 15)
	{
		cnt += ft_print_hex(n / 16, c);
		cnt += ft_print_hex(n % 16, c);
	}
	else
	{
		write(1, &hex[n % 16], 1);
		cnt++;
	}
	return (cnt);
}
