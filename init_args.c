/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:59:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/24 15:31:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_args(int ac, char **av, t_args *args)
{
	if (!ft_atoi(av[1]) || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (1);
	args->philos_num = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start_time = ft_get_time();
	args->finish = 0;
	if (ac == 6)
	{
		if (!ft_atoi(av[5]))
			return (1);
		args->eat_times = ft_atoi(av[5]);
	}
	return (0);
}
