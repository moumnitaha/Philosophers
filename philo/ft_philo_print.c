/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:57:14 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/13 15:30:52 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_print(t_args *args, int id, char *msg)
{
	long long	now;

	now = ft_get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(args->print_msg));
	if (!(args->finish))
		printf("%lld\t%d\t%s", now - args->start_time, id, msg);
	pthread_mutex_unlock(&(args->print_msg));
	return (0);
}
