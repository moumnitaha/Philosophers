/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:22:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/23 16:09:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	printf("[%ld]", tp.tv_sec);
	if (ac < 5 || ac > 6)
		return (0);
}
