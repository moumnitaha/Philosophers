/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:31:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/23 16:04:48 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_args{
	int				philos_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	int				eat_times;
	int				finish;
	pthread_mutex_t	forks;
	pthread_mutex_t	print;
}	t_args;

typedef struct s_philo{
	int		id;
	int		left;
	int		right;
	int		last_eat_time;
	int		eat_count;
	t_args	args;
}	t_philo;

int			ft_init_args(int ac, char **av, t_args *args);
long long	ft_get_time(void);
#endif