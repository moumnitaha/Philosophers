/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:31:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/19 01:31:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

# define BOLD  "\033[1m"
# define GREEN  "\033[1;32m"
# define RED  "\033[1;31m"
# define CYAN  "\033[1;36m"
# define END " \033[0m"

typedef struct s_args{
	int				philos_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	int				eat_times;
	int				finished_eat;
	int				finish;
	int				total_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_msg;
	pthread_mutex_t	m_finished_eat;
	pthread_mutex_t	m_finish;
}	t_args;

typedef struct s_philo{
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	m_last_eat;
}	t_philo;

int			ft_init_args(char **av_t, t_args *args);
int			ft_init_philo(t_philo **philo, t_args *args);
int			ft_philo_print(t_args *args, int id, char *msg);
int			ft_philo_routine(t_args *args, t_philo *philo);
int			ft_philo_start(t_args *args, t_philo *philo);
int			ft_strlen(char *str);
int			av_size(int ac, char **av);
int			tab_size(char **array);
void		ft_await(long long time);
int			count_words(char const *s, char c);
void		*free_mem(char **array);
void		ft_philo_finish(t_args *args, t_philo *philos);
void		ft_free_thread(t_args *args, t_philo *philo);
void		ft_join_threads(t_args *args, t_philo *philo);
long long	ft_get_time(void);
long long	elapsed_time(long long time);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		**split_args(int ac, char **av);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int d);
#endif