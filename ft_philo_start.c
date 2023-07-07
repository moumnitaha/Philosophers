/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:31:12 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 16:34:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread_action(void *argv)
{
	t_args	*args;
	t_philo	*philo;

	philo = argv;
	args = &philo->args;
	if (philo->id % 2)
		usleep(1000);
	while (!(args->finish))
	{
		ft_philo_action(args, philo);
		ft_philo_print(args, philo->id, "is sleeping\n");
		ft_await_time(args->time_to_sleep, args);
		ft_philo_print(args, philo->id, "is thinking\n");
	}
	return (0);
}

int	ft_philo_start(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		philo[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philo[i].thread), NULL,
				ft_thread_action, &(philo[i])))
			return (1);
		i++;
	}
	ft_philo_finish(args, philo);
	ft_free_thread(args, philo);
	return (0);
}
