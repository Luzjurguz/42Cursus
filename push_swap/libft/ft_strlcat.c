/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:14:22 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/04/26 16:00:51 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	sizedest;
	unsigned int	sizesrc;

	sizedest = ft_strlen(dest);
	sizesrc = ft_strlen(src);
	a = 0;
	b = 0;
	if (size <= sizedest)
	{
		return (sizesrc + size);
	}
	while (dest[b] != '\0')
	{
		b++;
	}
	while (src[a] != '\0' && a < (size - sizedest - 1))
	{
		dest[b] = src[a];
		b++;
		a++;
	}
	dest[b] = '\0';
	return (sizedest + sizesrc);
}

// int	main(void)
// {
// 	char	b1[] = "hola";
// 	char	a1[] = "holita";

// 	printf("%d", ft_strlcat(a1, b1, 4));
// 	printf("%d", strlcat(a1, b1, 4));
// }
