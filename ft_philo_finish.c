/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 12:44:36 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_finish(t_args *args, t_philo *philo)
{
	int			i;
	long long	now;

	while (!(args->finish))
	{
		printf("eat times:[%d] finished:[%d]\n", args->eat_times, args->finished_eat);
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
				ft_philo_print(args, philo->id, "\033[1;31mdied\033[0m\n");
				args->finish = 1;
				break ;
			}
			i++;
		}
	}
}
