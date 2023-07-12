/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 19:11:59 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philos;

	memset(&args, 0, sizeof(t_args));
	if (ac < 5 || ac > 6)
		return (0);
	if (ft_init_args(ac, av, &args))
	{
		printf("Error init args\n");
		exit(0);
	}
	if (ft_init_philo(&philos, &args))
	{
		printf("Error init philo\n");
		exit(0);
	}
	if (ft_philo_start(&args, philos))
	{
		printf("Error start philo\n");
		exit(0);
	}
	return (0);
}
