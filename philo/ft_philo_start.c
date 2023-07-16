/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:31:12 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/16 19:44:44 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread_action(void *arg)
{
	t_args	*args;
	t_philo	*philo;

	philo = arg;
	args = philo->args;
	if (philo->id % 2)
		ft_await(50);
	while (1)
	{
		pthread_mutex_lock(&(args->m_finish));
		if (args->finish == 1)
		{
			pthread_mutex_unlock(&(args->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(args->m_finish));
		ft_philo_routine(args, philo);
		ft_await(10);
	}
	return (0);
}

int	ft_philo_start(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		philos[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philos[i].thread), NULL,
				ft_thread_action, &(philos[i])))
			return (1);
		i++;
	}
	ft_philo_finish(args, philos);
	printf(GREEN"SALINA"END"\n");
	ft_join_threads(args, philos);
	printf(CYAN"JOINED"END"\n");
	ft_free_thread(args, philos);
	return (0);
}
