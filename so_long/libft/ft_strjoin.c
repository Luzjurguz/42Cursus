/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:25:41 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/06/05 23:00:14 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = malloc((ft_strlen(s2) + ft_strlen(s1)) + 1);
	if (!s3)
		return (0);
	if(!s1)
		s1 = ft_strdup("");
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		s3[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	s3[i + ft_strlen(s1)] = '\0';
	return (free(s1),s3);
}
