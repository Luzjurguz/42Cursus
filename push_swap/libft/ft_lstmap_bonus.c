/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:43:25 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/06/15 16:58:22 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*pnodo;

	if (!lst)
		return (NULL);
	pnodo = malloc(sizeof(t_list));
	if (!pnodo)
		return (NULL);
	newlst = pnodo;
	newlst->content = f(lst->content);
	while (lst->next)
	{
		lst = lst->next;
		newlst->next = malloc(sizeof(t_list));
		if (!newlst->next)
		{
			ft_lstclear(&pnodo, del);
			return (0);
		}
		newlst->next->content = f(lst->content);
		newlst = newlst->next;
	}
	newlst->next = NULL;
	return (pnodo);
}
