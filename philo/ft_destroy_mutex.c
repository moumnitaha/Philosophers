/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 19:15:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_num)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		i++;
	}
}
