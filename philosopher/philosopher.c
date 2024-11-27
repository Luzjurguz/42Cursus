/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:11:54 by luz-mjur          #+#    #+#             */
/*   Updated: 2024/11/27 20:51:29 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	create_philoarr(t_philo **philos, int n)
{
	int	a;

	a = 1;
	**philos = malloc(sizeof(t_philo) * n);
	if (!**philos)
		return (NULL);
	while (a < n)
	{
		philos[a] = malloc(sizeof(t_philo));
		if (!philos[a])
			return (NULL);
		philos[a]->id = a;
		a++;
	}
}
int	create_forkarr(t_fork *fork, int n)
{
	int	a;

	a = 0;
	fork = malloc(sizeof(t_fork) * n);
	if (!fork)
		return (NULL);
}

/*void	print_status(char c, int time, t_philo id)
{
	if(c == d)
	{
//		printf("%")
	}
}
*/
int	pars_arg(t_fork *fork, t_philo *philo, char **av)
{
	philo->number_of_philosophers = ft_atoi(av[1]);
	fork->number_of_forks = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	}
}
int	main(int ac, char **av)
{
	t_philo *philo;
	t_fork *fork;
	t_data **philos;
	if (ac == 5 || ac == 6)
	{
		pars_arg(fork, philo, **av);
	}
	else
		return (printf("%s", "ERROR : wrong arguments!"));

	create_philoarr(**philos, philo->number_of_philosophers);
	create_forkarr(fork, fork->number_of_forks);
	
	
}