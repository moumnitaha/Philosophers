/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:54:55 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/16 14:08:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_join(philos[i].thread, NULL))
			printf(RED"Error joining thread"END"\n");
		i++;
	}
}
