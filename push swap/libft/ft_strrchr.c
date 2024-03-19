/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:51:14 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/05 13:52:00 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	cnt;

	cnt = ft_strlen(str);
	while (cnt > 0 && str[cnt] != (char)c)
		cnt--;
	if (str[cnt] == (char)c)
		return ((char *)&str[cnt]);
	return (0);
}
