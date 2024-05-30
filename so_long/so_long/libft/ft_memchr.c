/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:15:08 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/12 17:03:38 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t cnt;
	char *str;

	cnt = 0;
	str = (char *)s;
	while (cnt < n)
	{
		if (str[cnt] == (char)c)
			return (str + cnt);
		cnt++;
	}
	return (0);
}