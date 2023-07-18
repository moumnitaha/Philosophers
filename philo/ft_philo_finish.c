/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/18 11:53:50 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish_eat(t_args *args)
{
	if (args->eat_times && args->finished_eat == args->total_eat)
	{
		pthread_mutex_lock(&(args->m_finish));
		args->finish = 1;
		pthread_mutex_unlock(&(args->m_finish));
		pthread_mutex_unlock(&(args->m_finished_eat));
		return (1);
	}
	return (0);
}

int	check_death(t_args *args, t_philo *philo, long long now)
{
	if (now - philo->last_eat_time >= args->time_to_die)
	{
		pthread_mutex_lock(&(args->m_finish));
		args->finish = 1;
		pthread_mutex_unlock(&(args->m_finish));
		pthread_mutex_unlock(&(philo->m_last_eat));
		if (args->philos_num == 1)
			pthread_mutex_unlock(&(args->forks[philo->left]));
		pthread_mutex_lock(&(philo->m_last_eat));
		printf("%lld\t%d\tdied\n", now - philo->last_eat_time, philo->id);
		pthread_mutex_unlock(&(philo->m_last_eat));
		return (1);
	}
	return (0);
}

void	ft_philo_finish(t_args *args, t_philo *philos)
{
	int			i;
	long long	now;

	while (!(args->finish))
	{
		pthread_mutex_lock(&(args->m_finished_eat));
		if (check_finish_eat(args))
			break ;
		pthread_mutex_unlock(&(args->m_finished_eat));
		i = 0;
		now = ft_get_time();
		while (i < args->philos_num)
		{
			pthread_mutex_lock(&(philos[i].m_last_eat));
			if (check_death(args, &(philos[i]), now))
				break ;
			pthread_mutex_unlock(&(philos[i].m_last_eat));
			i++;
		}
	}
}
