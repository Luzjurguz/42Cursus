/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:48:17 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/12 16:16:37 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cnt;
	char	*str1;
	char	*str2;

	cnt = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (cnt < n && (str1[cnt] != '\0' || str2[cnt] != '\0'))
	{
		if (str1[cnt] != str2[cnt])
		{
			return (str1[cnt] - (str2[cnt]));
		}
		cnt++;
	}
	return (0);
}
