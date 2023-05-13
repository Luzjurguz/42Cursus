/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:40:15 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/13 17:08:09 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cont;
	size_t 	cont1;
	char	*b;
	char	*l;
	char	c;
	
	cont = 0;
	cont1 = 0;
	c = cont1;
	b = (char *)big;
	l = (char *)little;
	if (!l)
		return ((char *)b);
	while (b [cont] != '\0')
	{
		cont++;
		if (l[cont] == b[cont1])
		{
			return ((char *)b + cont);
			cont++;
			cont1++;
		}	
		else if(l[cont]!= b[cont1])
			cont1++;	
	}
	return(0);
}
