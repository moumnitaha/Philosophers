/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/24 18:32:30 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char **av)
{
	t_args	*args;

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
	return (0);
}
