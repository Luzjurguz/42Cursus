/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:13:44 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:57:00 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node->next != NULL && node->content < node->next->content)
	{
		node = node->next;
	}
	if (node->next == NULL)
		return (1);
	return (0);
}

// void	print_lists(t_ab *ab)
// {
// 	t_list	*node1;
// 	t_list	*node2;

// 	node1 = ab->a;
// 	node2 = ab->b;
// 	while (node1 != NULL)
// 	{
// 		printf("Contenido A: %li %i\n", node1->content, node1->pos_obj);
// 		node1 = node1->next;
// 	}
// 	while (node2 != NULL)
// 	{
// 		printf("Contenido B: %li %i\n", node2->content, node2->pos_obj);
// 		node2 = node2->next;
// 	}
// }

void	init_ab(int argc, char **argv, t_ab *ab)
{
	int		cnt;
	t_list	*node;

	ab->a = malloc(sizeof(t_list));
	ab->a->content = ft_atol(argv[1]);
	ab->a->next = malloc(sizeof(t_list));
	node = ab->a->next;
	cnt = 2;
	while (cnt < argc - 1 && argv[cnt])
	{
		node->content = ft_atol(argv[cnt]);
		node->next = malloc(sizeof(t_list));
		node = node->next;
		cnt++;
	}
	node->content = ft_atol(argv[cnt]);
	node->next = NULL;
	posi_act(ab->a);
}

int	abs(int abs)
{
	if (abs < 0)
	{
		abs = abs * -1;
	}
	return (abs);
}

int	size(t_list *list)
{
	t_list	*node;
	int		cnt;

	cnt = 0;
	node = list;
	while (node)
	{
		cnt++;
		node = node->next;
	}
	return (cnt);
}
