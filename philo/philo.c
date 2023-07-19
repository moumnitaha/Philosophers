/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/19 09:29:09 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_error_msg(char *msg, char **av_t)
{
	printf(RED"%s"END"\n", msg);
	free_mem(av_t);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philos;
	char	**av_t;

	memset(&args, 0, sizeof(t_args));
	av_t = split_args(ac, av);
	if (tab_size(av_t) < 4 || tab_size(av_t) > 5 || check_args(ac, av))
		return (put_error_msg("Run ./philo arg1 arg2 arg3 arg4 [arg5]", av_t));
	if (ft_init_args(av_t, &args))
		return (put_error_msg("Error init args", av_t));
	if (ft_init_philo(&philos, &args))
		return (put_error_msg("Error init philosophers", av_t));
	if (ft_philo_start(&args, philos))
		return (put_error_msg("Error start philosophers", av_t));
	free_mem(av_t);
	return (0);
}
