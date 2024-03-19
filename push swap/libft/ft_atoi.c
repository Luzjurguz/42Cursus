/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:54:52 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/18 15:54:52 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	cont;
	int	num;
	int	b;

	num = 0;
	cont = 0;
	b = 0;
	while ((str[cont] >= 9 && str[cont] <= 13) || (str[cont] == 32))
		cont++;
	if (str[cont] == '-')
	{
		cont++;
		b = 1;
	}
	else if (str[cont] == '+')
		cont++;
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		num = num * 10 + (str[cont] - '0');
		cont++;
	}
	if (b == 1)
		num *= -1;
	return (num);
}
