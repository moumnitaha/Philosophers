/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:31:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/07/19 02:29:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_splited(char **splited)
{
	if (*splited == NULL)
	{
		free_mem(splited);
		return (1);
	}
	return (0);
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!i && (str[0] == '-' || str[0] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (count < ft_strlen((char *)s))
	{
		ptr[count] = s[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

int	av_size(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		size += count_words(av[i], ' ');
		i++;
	}
	return (size);
}

char	**split_args(int ac, char **av)
{
	char			**splited;
	char			**a;
	char			**tmp;
	int				i;
	int				j;

	i = 1;
	j = 0;
	a = malloc((av_size(ac, av) + 1) * sizeof(char *));
	while (i < ac)
	{
		splited = ft_split(av[i], ' ');
		if (check_splited(splited))
			break ;
		tmp = splited;
		while (*splited)
		{
			a[j] = ft_strdup(*splited);
			splited++;
			j++;
		}
		free_mem(tmp);
		i++;
	}
	a[j] = NULL;
	return (a);
}
