/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:48:27 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:33:20 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	int			cont;
	long int	num;
	int			b;

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

t_ab	*frees(t_ab *ab)
{
	t_list	*node;

	node = ab->a;
	while (node)
	{
		free(node);
		node = node->next;
	}
	ab->a = NULL;
	free(ab);
	return (NULL);
}

char	**fresplit(char **argv)
{
	int	cnt;

	cnt = 0;
	while (argv[cnt])
	{
		free(argv[cnt]);
		cnt++;
	}
	free(argv[cnt]);
	free(argv);
	return (NULL);
}
