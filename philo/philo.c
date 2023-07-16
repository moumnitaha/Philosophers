/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/16 14:27:01 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_error_msg(char *msg)
{
	printf(RED"%s"END"\n", msg);
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philos;

	memset(&args, 0, sizeof(t_args));
	if (ac < 5 || ac > 6)
		return (put_error_msg("Error: use ./philo arg1 arg2 arg3 arg4 [arg5]"));
	if (ft_init_args(ac, av, &args))
		return (put_error_msg("Error init args"));
	if (ft_init_philo(&philos, &args))
		return (put_error_msg("Error init philosophers"));
	if (ft_philo_start(&args, philos))
		return (put_error_msg("Error start philosophers"));
	return (0);
}
