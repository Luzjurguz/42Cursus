/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:22:09 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/11/27 20:59:25 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int		id;
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_sleep;
	int		time_to_eat;
	int		number_of_times_each_philosopher_must_eat;

}			t_philo;

typedef struct s_fork
{
	int		number_of_forks;
	int		r_fork;
	int		l_fork;
	int		f_mutex;

}			t_fork;

typedef struct s_data
{
	t_philo	**philos;
	t_fork	*forks;

}			t_data;

int			ft_atoi(const char *str);
void		print_status(char c, int time, t_philo id);
int			create_philoarr(t_philo **philos, int n);
int			create_forkarr(t_fork *fork, int n);

#endif