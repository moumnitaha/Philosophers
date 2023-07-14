/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/14 14:31:20 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_await(long long time)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (1)
	{
		now = ft_get_time();
		if ((now - start >= time))
			break ;
		usleep(50);
	}
}
int ft_philo_routine(t_args *args, t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	if (philo->left < philo->right)
	{
		first_fork = philo->left;
		second_fork = philo->right;
	}
	else
	{
		first_fork = philo->right;
		second_fork = philo->left;
	}
	pthread_mutex_lock(&(args->forks[first_fork]));
	ft_philo_print(args, philo->id, "has taken a fork\n");
	pthread_mutex_lock(&(args->forks[second_fork]));
	ft_philo_print(args, philo->id, "has taken a fork\n");
	ft_philo_print(args, philo->id, "is eating\n");
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(&(philo->m_last_eat));
	pthread_mutex_lock(&(args->m_finished_eat));
	args->finished_eat++;
	pthread_mutex_unlock(&(args->m_finished_eat));
	philo->eat_count++;
	ft_await(args->time_to_eat);
	pthread_mutex_unlock(&(args->forks[second_fork]));
	pthread_mutex_unlock(&(args->forks[first_fork]));
	ft_philo_print(args, philo->id, "is sleeping\n");
	ft_await(args->time_to_sleep);
	ft_philo_print(args, philo->id, "is thinking\n");
	return (0);
}
