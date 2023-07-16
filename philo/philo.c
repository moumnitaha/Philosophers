/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/16 09:25:54 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philos;

	memset(&args, 0, sizeof(t_args));
	if (ac < 5 || ac > 6)
	{
		printf(RED"Error: use ./philo arg1 arg2 arg3 arg4 <arg5?>"END"\n");
		return (0);
	}
	if (ft_init_args(ac, av, &args))
	{
		printf(RED"Error init args"END"\n");
		return (0);
	}
	if (ft_init_philo(&philos, &args))
	{
		printf(RED"Error init philo"END"\n");
		return (0);
	}
	if (ft_philo_start(&args, philos))
	{
		printf(RED"Error start philo"END"\n");
		return (0);
	}
	return (0);
}
