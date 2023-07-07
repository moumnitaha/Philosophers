/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 19:00:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_routine(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&(args->forks[philo->left]));
	ft_philo_print(args, philo->id, "has taken a fork\n");
	pthread_mutex_lock(&(args->forks[philo->right]));
	ft_philo_print(args, philo->id, "has taken a fork\n");
	ft_philo_print(args, philo->id, "is eating\n");
	philo->last_eat_time = ft_get_time();
	philo->eat_count++;
	args->finished_eat++;
	usleep(args->time_to_eat * 1000);
	pthread_mutex_unlock(&(args->forks[philo->right]));
	pthread_mutex_unlock(&(args->forks[philo->left]));
	ft_philo_print(args, philo->id, "is sleeping\n");
	usleep(args->time_to_sleep * 1000);
	ft_philo_print(args, philo->id, "is thinking\n");
	return (0);
}
