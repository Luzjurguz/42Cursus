/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:15:08 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/12 16:16:54 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t cnt;
	const char *str;

	cnt = 0;
	str = (char *)s;
	while (cnt < n)
	{
		cnt++;
		if (str[cnt] == c)
			return (str[cnt]);
	}
	return (0);
}