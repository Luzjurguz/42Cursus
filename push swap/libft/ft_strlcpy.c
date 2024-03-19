/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:38:31 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/04/26 17:08:40 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	size1;

	a = 0;
	size1 = (size_t)ft_strlen(src);
	if (size == 0)
	{
		return (size1);
	}
	while (src[a] != '\0' && a < size - 1)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (size1);
}
/*
int main (void)
{
	char	dest1[20] = "hola";
	char	src1[20] = "adios";
	char	dest2[20] = "hola";
	char	src2[20] = "adios";
	size_t	l1;
	size_t	l2;
	int i = 2;
	
	l1 = strlcpy(dest1, src1, i);
	printf("%zu\n", l1);
	printf("%s\n", dest1);
	l2 = ft_strlcpy(dest2, src2, i);
	printf("%zu\n", l2);
	printf("%s\n", dest2);
}
*/