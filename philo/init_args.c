/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:59:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/18 19:14:03 by tmoumni          ###   ########.fr       */
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

int	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_error_syntax(char **str, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (!str[j][0])
			return (1);
		while (ft_iswhitespace(str[j][i]) && i < ft_strlen(str[j]))
			i++;
		if (str[j][i] == '+' && i < ft_strlen(str[j]))
			i++;
		while (ft_isdigit(str[j][i]) && i < ft_strlen(str[j]))
			i++;
		while (i < ft_strlen(str[j]))
		{
			if (str[j][i] != ' ')
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

int	ft_init_args(int ac, char **av, t_args *args)
{
	if (ft_error_syntax(av, ac))
		return (1);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (1);
	args->philos_num = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start_time = ft_get_time();
	args->finish = 0;
	args->finished_eat = 0;
	args->total_eat = 0;
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		args->eat_times = ft_atoi(av[5]);
		args->total_eat = args->eat_times * args->philos_num;
	}
	if (ft_init_args_mutex(args))
		return (1);
	return (0);
}
