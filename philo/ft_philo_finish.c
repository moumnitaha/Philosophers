/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/14 19:04:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_finish(t_args *args, t_philo *philos)
{
	int			i;
	long long	now;

	while (!(args->finish))
	{
		pthread_mutex_lock(&(args->m_finished_eat));
		if (args->eat_times && args->finished_eat == args->total_eat)
		{
			pthread_mutex_lock(&(args->m_finish));
			args->finish = 1;
			pthread_mutex_unlock(&(args->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(args->m_finished_eat));
		i = 0;
		while (i < args->philos_num)
		{
			now = ft_get_time();
			pthread_mutex_lock(&(philos[i].m_last_eat));
			if (now - philos[i].last_eat_time >= args->time_to_die)
			{
				ft_philo_print(args, philos[i].id, RED"died"END"\n");
				pthread_mutex_lock(&(args->m_finish));
				args->finish = 1;
				pthread_mutex_unlock(&(args->m_finish));
				break ;
			}
			pthread_mutex_unlock(&(philos[i].m_last_eat));
			i++;
		}
	}
	ft_destroy_mutex(args);
}
