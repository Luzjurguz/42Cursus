/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:11:56 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/18 18:12:47 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	if (!dst && !src)
		return (0);
	if (dst1 >= src1)
		while (n-- > 0)
			dst1[n] = src1[n];
	else
		while (i++ < n)
			dst1[i - 1] = src1[i - 1];
	return ((void *)dst1);
}
