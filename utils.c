/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:37:10 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/19 00:57:08 by aivanyan         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	return (sign * number);
}

int	getting_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	int	start;
	int	cur;
	
	start = getting_time();
	cur = getting_time();
	while (cur - start < ms)
	{
		usleep(10);
		cur = getting_time();
	}
}

void	is_died(t_philo *philo)
{
	int	cur;
	int	dif;
	
	cur = getting_time();
	dif = cur - philo->last_eat_time;
	if (dif >= philo->time_to_die)
		philo->must_die = 1;
}

void	ft_printf(int time, int num, char *str, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%d %d ", time, num);
	printf("%s\n", str);
	pthread_mutex_unlock(print);
}
