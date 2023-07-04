/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:59:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/04 12:47:04 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_args_mutex(t_args *args)
{
	int	i;

	if (pthread_mutex_init(&(args->print), NULL))
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_num);
	if (!args->forks)
		return (1);
	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_mutex_init(&(args->forks)[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_args(int ac, char **av, t_args *args)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (1);
	args->philos_num = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start_time = ft_get_time();
	args->finish = 0;
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		args->eat_times = ft_atoi(av[5]);
	}
	if (ft_init_args_mutex(args))
		return (1);
	return (0);
}
