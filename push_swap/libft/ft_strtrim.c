/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:04:06 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/15 16:02:24 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	slen;
	char	*s2;

	if (s1[0] == '\0' && set[0] == '\0')
	{
		s2 = malloc(sizeof(char));
		if (!s2)
			return (0);
		s2[0] = '\0';
		return (s2);
	}
	if (!s1 || !set)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (ft_strchr(set, s1[slen]) && slen > 0)
	{
		slen--;
	}
	s2 = ft_substr(s1, 0, slen + 1);
	return (s2);
}
