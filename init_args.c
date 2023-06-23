/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:59:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/23 18:48:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_init_args(int ac, char **av, t_args *args)
{
	args->philos_num = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start_time = ft_get_time();
	if (ac == 6)
	{
		if (!ft_atoi(av[5]))
			return (1);
		args->eat_times = ft_atoi(av[5]);
	}
}
