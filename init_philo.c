/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:23:49 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/07 16:04:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_philo **philo, t_args *args)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * args->philos_num);
	if (!philo)
		return (1);
	while (i < args->philos_num)
	{
		(*philo)[i].args = *args;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % args->philos_num;
		(*philo)[i].last_eat_time = -1;
		(*philo)[i].eat_count = 0;
		i++;
	}
	return (0);
}
