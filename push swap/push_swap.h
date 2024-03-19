/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:42 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/03/13 01:56:57 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long int		content;
	int				pos_act;
	int				pos_obj;
	int				cos_a;
	int				cos_b;
	struct s_list	*next;

}					t_list;

typedef struct s_ab
{
	t_list			*a;
	t_list			*b;
	int				a_len;
	int				b_len;
}					t_ab;

/**
 * @brief  deja solo 3 num en a y pasa el resto a b
 * 
 * @param ab 
 */
void				check_three(t_ab *ab);

/**
 * @brief ver si la lista está ordenada.
 * 
 * @param lst 
 * @return int 
 */
int					check_order(t_list *lst);

/**
 * @brief ordena los tres numero de a
 * 
 * @param ab 
 */
void				order_three_num(t_ab *ab);

/**
 * @brief hace el indice de las listas
 * 
 * @param list 
 * @return int 
 */
void				posi_act(t_list *list);

/**
 * @brief mueve los staks
 * 
 * @param ab 
 */
void				order_b(t_ab *ab);

/**
 * @brief saca el tamaño de a y usa check three para pasar los num a b
 * 
 * @param ab 
 */
void				max_order(t_ab *ab);

/**
 * @brief hace el coste de a y b
 * 
 * @param ab 
 */
void				pos_obj(t_ab *ab);

/**
 * @brief si está en la mitad de arriba positivo, en la de abajo negativo
 * 
 * @param list 
 * @param pos 
 */
int					half_sig(t_list *list, int pos);

/**
 * @brief hace la lista a y b
 * 
 * @param argc
 * @param argv 
 * @param ab 
 */
void				init_ab(int argc, char **argv, t_ab *ab);

/**
 * @brief imprime las listas
 * 
 * @param ab 
 */
//void				print_lists(t_ab *ab);

/**
 * @brief hacer que el primer numer de la lista origen(a o b) (nodo 1) pase a
 * la lista de destino (b o a) y borrar el primero del origen.
 * 
 * @param ab 
 */
void				pa(t_ab *ab);

/**
 * @brief hacer que el primer numer de la lista origen(a o b) (nodo 1) pase a
 * la lista de destino (b o a) y borrar el primero del origen.
 * 
 * @param ab 
 */
void				pb(t_ab *ab);

/**
 * @brief intercambia los dos primeros numeros de la lista, si hay
 * menos de dos no hace nada.
 * 
 * @param lst 
 * @param bull 
 */
void				sa(t_list *lst, int bull);

/**
 * @brief intercambia los dos primeros numeros de la lista, si hay
 * menos de dos no hace nada.
 * 
 * @param lst 
 * @param bull 
 */
void				sb(t_list *lst, int bull);

/**
 * @brief el primero pasa a ser el último.
 * 
 * @param lst 
 * @param bull 
 * @return t_list* 
 */
t_list				*ra(t_list *lst, int bull);

/**
 * @brief el primero pasa a ser el último.
 * 
 * @param lst 
 * @param bull 
 * @return t_list* 
 */
t_list				*rb(t_list *lst, int bull);

/**
 * @brief el ultimo pasa a ser el primero
 * 
 * @param lst 
 * @param bull 
 * @return t_list* 
 */
t_list				*rra(t_list *lst, int bull);
t_list				*rrb(t_list *lst, int bull);
void				ss(t_ab *ab);
t_ab				*rr(t_ab *ab);
t_ab				*rrr(t_ab *ab);
void				costes(t_ab *ab);
t_list				*baratillo(t_ab *ab);
int					size(t_list *list);
int					abs(int abs);
int					check_order(t_list *lst);
t_ab				*movi(t_ab *ab, t_list *cheap);
void				pos_obja(t_ab *ab);
int					re_obj(t_ab *ab, t_list *nb, int menor, int poso);
long int			ft_atol(const char *str);
char				**fresplit(char **argv);
void				interror(char **argv);
void				masmenos(char **argv);
void				too_much(t_list *list);
void				cero(t_list *list);
void				repenum(t_list *list);
t_ab				*frees(t_ab *ab);
#endif