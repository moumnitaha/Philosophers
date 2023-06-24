/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/24 22:46:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_philo	*philos;

	args = malloc(sizeof(t_args));
	if (ac < 5 || ac > 6)
		return (0);
	if (!ft_init_args(ac, av, args))
	{
		printf("philos num : [%d]\n", args->philos_num);
		printf("time to die: [%lld]\n", args->time_to_die);
		printf("time to eat: [%lld]\n", args->time_to_eat);
		printf("time to slp: [%lld]\n", args->time_to_sleep);
		printf("finish time: [%d]\n", args->finish);
		printf("start time : [%lld]\n", args->start_time);
		if (ac == 6)
			printf("eat times  : [%d]\n", args->eat_times);
	}
	if (!ft_init_philo(&philos, args))
	{
		for (int i = 0; i < args->philos_num; i++)
		{
			printf("id\t[%d]\n", philos[i].id);
			printf("count\t[%d]\n", philos[i].eat_count);
			printf("last\t[%d]\n", philos[i].last_eat_time);
			printf("left\t[%d]\n", philos[i].left);
			printf("right\t[%d]\n", philos[i].right);
		}
	}
	return (0);
}
