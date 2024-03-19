/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errores.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:43:39 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:45:53 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	interror(char **argv)
{
	int	cnt;
	int	cnt2;

	cnt = 1;
	while (argv[cnt])
	{
		cnt2 = 0;
		while (argv[cnt][cnt2])
		{
			if (ft_isdigit(argv[cnt][cnt2]) == 0)
			{
				if (argv[cnt][cnt2] != '+' && argv[cnt][cnt2] != '-')
				{
					if (argv[cnt][cnt2] != ' ')
					{
						ft_putstr_fd("error de input\n", 2);
						exit(1);
					}
				}
			}
			cnt2++;
		}
		cnt++;
	}
}

void	masmenos(char **argv)
{
	int	cnt;
	int	cnt2;

	cnt = 1;
	while (argv[cnt])
	{
		cnt2 = 0;
		while (argv[cnt][cnt2])
		{
			if (argv[cnt][cnt2] == '-' || argv[cnt][cnt2] == '+')
			{
				if (ft_isdigit(argv[cnt][cnt2 - 1]) || (argv[cnt][cnt2
						+ 1] == ' ' || argv[cnt][cnt2 + 1] == '\0')
					|| (argv[cnt][cnt2 + 1] == '-' || argv[cnt][cnt2
						+ 1] == '+'))
				{
					ft_putstr_fd("error de signo\n", 2);
					exit(1);
				}
			}
			cnt2++;
		}
		cnt++;
	}
}

void	too_much(t_list *list)
{
	t_list	*node;

	node = list;
	while (node != NULL)
	{
		if (node->content > INT_MAX || node->content < INT_MIN)
		{
			ft_putstr_fd("error numero muy grandote D:\n", 2);
			exit(1);
		}
		node = node->next;
	}
}

void	cero(t_list *list)
{
	t_list	*node;
	int		cero;

	node = list;
	cero = 0;
	while (node != NULL)
	{
		if (node->content == 0 || node->content == +0 || node->content == -0)
			cero++;
		node = node->next;
	}
	if (cero > 1)
	{
		ft_putstr_fd("error numero repe >:(\n", 2);
		exit(1);
	}
}

void	repenum(t_list *list)
{
	t_list	*nod;
	t_list	*nod2;

	nod = list;
	while (nod != NULL)
	{
		nod2 = list;
		while (nod2 != NULL)
		{
			if (nod2->content == nod->content && nod2->pos_act != nod->pos_act)
			{
				ft_putstr_fd("error numero repe >:(\n", 2);
				exit(1);
			}
			nod2 = nod2->next;
		}
		nod = nod->next;
	}
}
