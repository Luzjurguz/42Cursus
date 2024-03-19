/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:56:33 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/02/09 23:50:31 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/ft_printf.h"

int	ft_format(va_list list, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(list, int)));
	if (c == 's')
		return (ft_print_str(va_arg(list, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_decimal_int(va_arg(list, int)));
	if (c == 'u')
		return (ft_print_u_int(va_arg(list, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(list, long unsigned int), c));
	if (c == 'p')
		return (ft_print_ppunt(va_arg(list, unsigned long int)));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		cnt;
	int		len;

	len = 0;
	cnt = 0;
	va_start(list, str);
	if (!str)
		return (-1);
	while (str[cnt])
	{
		if (str[cnt] == '%')
		{
			cnt++;
			len += ft_format(list, str[cnt++]);
		}
		else
		{
			write(1, &str[cnt++], 1);
			len++;
		}
	}
	va_end(list);
	return (len);
}

// int	main(void)
// {

// 	ft_printf("\n%i\n", ft_printf("%p", "test"));
// }
