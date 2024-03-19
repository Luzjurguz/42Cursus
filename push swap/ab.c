/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:33:51 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:56:33 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ab *ab)
{
	sa(ab->a, 1);
	sb(ab->b, 1);
	ft_putstr_fd("ss\n", 1);
}

t_ab	*rr(t_ab *ab)
{
	ab->a = ra(ab->a, 1);
	ab->b = rb(ab->b, 1);
	ft_putstr_fd("rr\n", 1);
	return (ab);
}

t_ab	*rrr(t_ab *ab)
{
	ab->a = rra(ab->a, 1);
	ab->b = rrb(ab->b, 1);
	ft_putstr_fd("rrr\n", 1);
	return (ab);
}
