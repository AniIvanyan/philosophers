/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:10:42 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/25 18:10:44 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	int	start;
	int	cur;

	start = get_time();
	cur = get_time();
	while (cur - start < ms)
	{
		usleep(10);
		cur = get_time();
	}
}

int	is_died(t_philo *philo)
{
	int	cur;
	int	dif;

	cur = get_time();
	dif = cur - philo->last_eat_time;
	if (dif >= philo->time_to_die)
		return (1);
	return (0);
}
