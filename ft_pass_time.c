/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:45:57 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/04 16:55:17 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	pass_time(long long time, t_args *args)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(args->finish))
	{
		now = ft_get_time();
		if ((now - start) >= time)
			break ;
		usleep(10);
	}
}
