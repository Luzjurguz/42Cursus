/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:05:15 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/18 15:54:57 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	m;

	m = count * size;
	str = malloc(m);
	if (str)
	{
		i = 0;
		while (i < m)
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}
