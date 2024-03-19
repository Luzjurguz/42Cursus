/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:42:21 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/05 13:43:49 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '\0' && str[cnt] != (char)c)
		cnt++;
	if (str[cnt] == (char)c)
	{
		return ((char *)&str[cnt]);
	}
	return (0);
}
