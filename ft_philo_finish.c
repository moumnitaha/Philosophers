/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/06 19:12:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_finish(t_args *args, t_philo *philo)
{
	int			i;
	long long	now;

	while (!(args->finish))
	{
		if ((args->eat_times != 0) && (args->philos_num == args->finished_eat))
		{
			args->finish = 1;
			break ;
		}
		i = 0;
		while (i < args->philos_num)
		{
			now = ft_get_time();
			if ((now - philo[i].last_eat_time) >= args->time_to_die)
			{
				ft_philo_print(args, philo->id, "died\n");
				args->finish = 1;
				break ;
			}
			i++;
		}
	}
}
