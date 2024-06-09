/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:40:15 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/18 14:07:19 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;

	i = 0;
	if (lit[0] == 0 || big == lit)
		return ((char *)big);
	litlen = ft_strlen(lit);
	j = litlen;
	while (big[i] != '\0' && j <= len)
	{
		if (!(ft_strncmp((char *)&big[i], (char *)lit, litlen)))
			return ((char *)&big[i]);
		i++;
		j++;
	}
	return (0);
}
