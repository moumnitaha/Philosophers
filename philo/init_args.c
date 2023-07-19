/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:59:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/19 10:35:09 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	tab_size(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	ft_error_syntax(char **str, int count)
{
	int	i;
	int	j;

	j = 0;
	while (j < count)
	{
		i = 0;
		if (!str[j][0])
			return (1);
		if (str[j][i] == '+' && i < ft_strlen(str[j]))
			i++;
		while (i < ft_strlen(str[j]))
		{
			if (!ft_isdigit(str[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_init_args_mutex(t_args *args)
{
	int	i;

	if (pthread_mutex_init(&(args->print_msg), NULL))
		return (1);
	if (pthread_mutex_init(&(args->m_finish), NULL))
		return (1);
	if (pthread_mutex_init(&(args->m_finished_eat), NULL))
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_num);
	if (!args->forks)
		return (1);
	i = 0;
	while (i < args->philos_num)
	{
		if (pthread_mutex_init(&(args->forks)[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_args(char **av_t, t_args *args)
{
	if (ft_error_syntax(av_t, tab_size(av_t)))
		return (1);
	if (ft_atoi(av_t[0]) <= 0 || ft_atoi(av_t[1]) <= 0
		|| ft_atoi(av_t[2]) <= 0 || ft_atoi(av_t[3]) <= 0)
		return (1);
	args->philos_num = ft_atoi(av_t[0]);
	args->time_to_die = ft_atoi(av_t[1]);
	args->time_to_eat = ft_atoi(av_t[2]);
	args->time_to_sleep = ft_atoi(av_t[3]);
	args->start_time = ft_get_time();
	args->finish = 0;
	args->finished_eat = 0;
	args->total_eat = 0;
	if (tab_size(av_t) == 5)
	{
		if (ft_atoi(av_t[4]) <= 0)
			return (1);
		args->eat_times = ft_atoi(av_t[4]);
		args->total_eat = args->eat_times * args->philos_num;
	}
	if (ft_init_args_mutex(args))
		return (1);
	return (0);
}
