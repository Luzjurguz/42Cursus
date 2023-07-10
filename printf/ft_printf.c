/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:56:33 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/07/05 21:43:30 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(va_list lista, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(lista, int)));
	if (c == 's')
		return (ft_print_str(va_arg(lista, char *)));
	if (c == 'd')
		return (ft_print_decimal_int(va_arg(lista, int)));
	if (c == 'u')
		return (ft_print_decimal_int(va_arg(lista, int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(lista, long unsigned int)));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	lista;
	int		cnt;
	int		len;

	len = 0;
	cnt = 0;
	va_start(lista, str);
	while (str[cnt])
	{
		if (str[cnt] == '%')
		{
			cnt++;
			len += ft_format(lista, str[cnt++]);
		}
		else
		{
			write(1, &str[cnt++], 1);
			len++;
		}
	}
	va_end(lista);
	return (len);
}
