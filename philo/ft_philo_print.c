/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:57:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/14 17:53:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	elapsed_time(long long time)
{
	long long	now;
	long long	elapsed;

	now = ft_get_time();
	elapsed = now - time;
	if (elapsed < 0)
		return (-1);
	return (elapsed);
}

int	ft_philo_print(t_args *args, int id, char *msg)
{
	pthread_mutex_lock(&(args->m_finish));
	if (args->finish == 0)
	{
		pthread_mutex_lock(&(args->print_msg));
		printf("%lld\t%d\t%s", elapsed_time(args->start_time), id, msg);
		pthread_mutex_unlock(&(args->print_msg));
	}
	pthread_mutex_unlock(&(args->m_finish));
	return (0);
}
