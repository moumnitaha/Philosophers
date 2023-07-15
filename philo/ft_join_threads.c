/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:54:55 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/15 15:51:51 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	if (args->philos_num == 1)
	{
		pthread_mutex_unlock(&(args->forks[philos[0].left]));
	}
	while (i < args->philos_num)
	{
		if (pthread_join(philos[i].thread, NULL))
			printf(RED"Error joining thread"END"\n");
		i++;
	}
}
