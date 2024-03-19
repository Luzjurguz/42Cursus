/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:52 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 02:00:28 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three_num(t_ab *ab)
{
	int	a;
	int	b;
	int	c;

	a = ab->a->content;
	b = ab->a->next->content;
	c = ab->a->next->next->content;
	if (a > b && b < c && a > c)
		ab->a = ra(ab->a, 0);
	else if (a > b && b > c)
	{
		ab->a = ra(ab->a, 0);
		sa(ab->a, 0);
	}
	else if (a < b && b > c && a > c)
		ab->a = rra(ab->a, 0);
	else if (a < b && b > c && c > a)
	{
		ab->a = rra(ab->a, 0);
		sa(ab->a, 0);
	}
	else if (a > b && b < c && c > a)
		sa(ab->a, 0);
}

void	check_three(t_ab *ab)
{
	if (ab->a_len == 1 || ab->a_len == 0)
		return ;
	else if (ab->a_len == 2)
		sa(ab->a, 0);
	else if (ab->a_len >= 3)
	{
		if (ab->a_len == 3)
			order_three_num(ab);
		else
		{
			while (ab->a_len > 3)
			{
				pb(ab);
				ab->a_len--;
			}
			order_three_num(ab);
		}
	}
	posi_act(ab->a);
}

void	max_order(t_ab *ab)
{
	t_list	*node_a;
	t_list	*sales;

	node_a = ab->a;
	ab->a_len = size(ab->a);
	check_three(ab);
	while (ab->b)
	{
		pos_obj(ab);
		costes(ab);
		sales = baratillo(ab);
		ab = movi(ab, sales);
	}
	while (check_order(ab->a) == 0)
	{
		pos_obja(ab);
		if (ab->a->pos_obj < size(ab->a) / 2)
			ab->a = ra(ab->a, 0);
		else
			ab->a = rra(ab->a, 0);
	}
}

void	init_abs(char **argv, t_ab *ab)
{
	int		cnt;
	t_list	*node;

	if (!argv[1])
		exit(0);
	ab->a = malloc(sizeof(t_list));
	ab->a->content = ft_atol(argv[0]);
	ab->a->next = malloc(sizeof(t_list));
	node = ab->a->next;
	cnt = 1;
	while (argv[cnt + 1])
	{
		node->content = ft_atol(argv[cnt]);
		node->next = malloc(sizeof(t_list));
		node = node->next;
		cnt++;
	}
	node->content = ft_atol(argv[cnt]);
	node->next = NULL;
	fresplit(argv);
	posi_act(ab->a);
}

int	main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc < 2)
	{
		ft_putstr_fd("Muy pocos argumentos :(\n", 2);
		exit(1);
	}
	ab = malloc(sizeof(t_ab));
	interror(argv);
	masmenos(argv);
	if (argc == 2)
		init_abs(ft_split(argv[1], ' '), ab);
	else
		init_ab(argc, argv, ab);
	repenum(ab->a);
	too_much(ab->a);
	if (check_order(ab->a))
	{
		ft_putstr_fd("ENHORABUENA, TU LISTA ESTA ORDENADA!!", 2);
		ab = frees(ab);
		return (0);
	}
	max_order(ab);
	ab = frees(ab);
}
