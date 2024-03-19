/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:11:11 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 00:34:46 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costes(t_ab *ab)
{
	t_list	*nb;

	nb = ab->b;
	ab->a_len = size(ab->a);
	ab->b_len = size(ab->b);
	while (nb)
	{
		if (nb->pos_obj > ab->a_len / 2)
			nb->cos_a = nb->pos_obj * -1;
		else
			nb->cos_a = nb->pos_obj;
		if (nb->pos_act > ab->b_len / 2)
			nb->cos_b = nb->pos_act * -1;
		else
			nb->cos_b = nb->pos_act;
		nb = nb->next;
	}
}

t_list	*baratillo(t_ab *ab)
{
	t_list	*bno;
	t_list	*sale;
	int		sum;

	sum = INT_MAX;
	bno = ab->b;
	while (bno)
	{
		if (abs(bno->cos_a) + abs(bno->cos_b) < sum)
		{
			sum = abs(bno->cos_a) + abs(bno->cos_b);
			sale = bno;
		}
		bno = bno->next;
	}
	return (sale);
}

int	re_obj(t_ab *ab, t_list *nb, int menor, int poso)
{
	t_list	*na;

	na = ab->a;
	while (na != NULL)
	{
		if (nb->content < na->content && na->content < menor)
		{
			menor = na->content;
			poso = na->pos_act;
		}
		na = na->next;
	}
	if (menor != INT_MAX)
		return (poso);
	na = ab->a;
	while (na != NULL)
	{
		if (na->content < menor)
		{
			menor = na->content;
			poso = na->pos_act;
		}
		na = na->next;
	}
	return (poso);
}

void	pos_obj(t_ab *ab)
{
	t_list	*nb;
	int		menor;
	int		pos;

	pos = 0;
	nb = ab->b;
	menor = INT_MAX;
	while (nb != NULL)
	{
		nb->pos_obj = re_obj(ab, nb, menor, pos);
		nb = nb->next;
	}
}

void	posi_act(t_list *list)
{
	t_list	*node;
	int		cnt;

	node = list;
	cnt = 0;
	while (node != NULL)
	{
		node->pos_act = cnt;
		node = node->next;
		cnt++;
	}
}
