/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:40:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/24 12:08:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isalnum(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (ft_isdigit(d) || ft_isalpha(d))
		return (1);
	return (0);
}
