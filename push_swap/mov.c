/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:26:51 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 00:35:10 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ab	*movi(t_ab *ab, t_list *cheap)
{
	int	cos_a;
	int	cos_b;

	cos_a = cheap->cos_a;
	cos_b = cheap->cos_b;
	if (cos_a == 0 && cos_b == 0)
		pa(ab);
	else if (cos_a < 0 && cos_b < 0)
		return (rrr(ab));
	else if (cos_a > 0 && cos_b > 0)
		return (rr(ab));
	else if (cos_a < 0)
		ab->a = rra(ab->a, 0);
	else if (cos_a > 0)
		ab->a = ra(ab->a, 0);
	else if (cos_b < 0)
		ab->b = rrb(ab->b, 0);
	else if (cos_b > 0)
		ab->b = rb(ab->b, 0);
	return (ab);
}

void	pos_obja(t_ab *ab)
{
	t_list	*na;
	int		menor;
	int		pos;

	pos = 0;
	na = ab->a;
	menor = INT_MAX;
	while (na != NULL)
	{
		na->pos_obj = re_obj(ab, na, menor, pos);
		na = na->next;
	}
}
