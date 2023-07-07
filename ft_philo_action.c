/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 14:45:51 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_action(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->forks[philo->left]));
	ft_philo_print(args, philo->id, "has taken a fork\n");
	if (args->philos_num != 1)
	{
		pthread_mutex_lock(&(args->forks[philo->right]));
		ft_philo_print(args, philo->id, "has taken a fork\n");
		ft_philo_print(args, philo->id, "is eating\n");
		philo->last_eat_time = ft_get_time();
		philo->eat_count++;
		ft_await_time(args->time_to_eat, args);
		pthread_mutex_unlock(&(args->forks[philo->right]));
	}
	pthread_mutex_unlock(&(args->forks[philo->left]));
	return (0);
}
