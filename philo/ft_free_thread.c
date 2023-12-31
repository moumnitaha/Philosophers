/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:54:31 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/15 16:02:51 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_thread(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(philo->m_last_eat));
	pthread_mutex_destroy(&(args->m_finish));
	pthread_mutex_destroy(&(args->m_finished_eat));
	pthread_mutex_destroy(&(args->print_msg));
	free(philo);
	free(args->forks);
	return ;
}
