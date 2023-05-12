/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:57:55 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/05/05 15:09:37 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	cnt;

	cnt = 0;
	while (cnt < n && (s1[cnt] != '\0' || s2[cnt] != '\0'))
	{
		if (s1[cnt] != s2[cnt])
		{
			return((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		}
		cnt++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "1234567";
// 	char s2[] = "3";
// 	int n;
// 	n = 4;
// 	printf("%i\n", ft_strncmp(s1, s2, n));
// 	printf("%i", strncmp(s1, s2, n));
// }