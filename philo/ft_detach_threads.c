/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detach_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:06:50 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/09 18:09:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_detach_threads(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_detach(philo[i].thread))
			printf(RED"Error detaching thread\n"END);
		i++;
	}
}
