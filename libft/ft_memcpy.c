/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:56:42 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/04/26 16:39:43 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;
	int		i;

	i = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	if (!src1 && !dst1)
	{
		return (0);
	}
	while (n > 0)
	{
		dst1[i] = src1[i];
		i++;
		n--;
	}
	return (dst1);
}
