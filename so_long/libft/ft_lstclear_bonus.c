/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:37:32 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/15 16:57:57 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo;

	while (*lst)
	{
		nodo = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = nodo;
	}
	*lst = NULL;
}
