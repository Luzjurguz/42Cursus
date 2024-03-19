/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:31:34 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/15 16:57:41 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ulti;

	if (!*lst)
		*lst = new;
	else
	{
		ulti = ft_lstlast(*lst);
		ulti->next = new;
	}
}
