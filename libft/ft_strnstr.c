/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:40:15 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/13 14:23:21 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little size_t len)
{
	size_t	cont;

	cont = 0;
	if (!little)
		return ((char *)big);
	while (cont < len)
	{
		if (little[cont] == big[cont])
			return ((char *)big[cont]);
		else
			cont++;
	}
	return (0);
}
