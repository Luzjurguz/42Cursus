/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:33:53 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:56:47 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ab *ab)
{
	t_list	*node;

	if (!ab->b)
	{
		ab->b = ab->a;
		ab->a = ab->a->next;
		ab->b->next = NULL;
	}
	else
	{
		node = ab->b;
		ab->b = ab->a;
		ab->a = ab->a->next;
		ab->b->next = node;
	}
	posi_act(ab->a);
	posi_act(ab->b);
	ft_putstr_fd("pb\n", 1);
}

void	sb(t_list *lst, int bull)
{
	int	sw;

	sw = lst->content;
	lst->content = lst->next->content;
	lst->next->content = sw;
	posi_act(lst);
	if (bull == 0)
		ft_putstr_fd("sb\n", 1);
}

t_list	*rb(t_list *lst, int bull)
{
	t_list	*node;
	t_list	*sw;

	if (!lst->next)
		return (lst);
	sw = lst->next;
	node = lst;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = node;
	node->next = NULL;
	posi_act(sw);
	if (bull == 0)
		ft_putstr_fd("rb\n", 1);
	return (sw);
}

t_list	*rrb(t_list *lst, int bull)
{
	t_list	*node;
	t_list	*sw;

	sw = lst;
	while (lst->next->next != NULL)
		lst = lst->next;
	node = lst->next;
	lst->next = NULL;
	node->next = sw;
	posi_act(node);
	if (bull == 0)
		ft_putstr_fd("rrb\n", 1);
	return (node);
}
