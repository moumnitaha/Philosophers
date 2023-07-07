/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:44:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 18:15:46 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	they_all_eat(t_args *args, t_philo *philos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!args->eat_times)
		return (0);
	while (i < args->philos_num)
	{
		if (philos[i].eat_count == args->eat_times)
			count++;
		i++;
	}
	return (count);
}

void	ft_philo_finish(t_args *args, t_philo *philos)
{
	int			i;
	long long	now;

	while (!(args->finish))
	{
		if (they_all_eat(args, philos) == args->philos_num)
		{
			printf("====>[%d]\n", args->finished_eat);
			printf("====>[%d]\n", philos->eat_count * args->philos_num);
			args->finish = 1;
			break ;
		}
		i = 0;
		while (i < args->philos_num)
		{
			now = ft_get_time();
			if (now - philos[i].last_eat_time >= args->time_to_die)
			{
				ft_philo_print(args, philos[i].id, RED"died"END"\n");
				args->finish = 1;
				break ;
			}
			i++;
		}
	}
}
