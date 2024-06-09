/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:49:34 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/15 15:43:03 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strf;
	size_t	cnt;
	size_t	lens;

	cnt = 0;
	if (!s || !f)
		return (0);
	lens = ft_strlen(s);
	strf = (char *)malloc(sizeof(char) * (lens + 1));
	if (!strf)
	{
		return (0);
	}
	while (cnt < lens)
	{
		strf[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	strf[cnt] = '\0';
	return (strf);
}
