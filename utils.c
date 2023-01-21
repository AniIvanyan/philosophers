/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:37:10 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/22 01:52:05 by zkarapet         ###   ########.fr       */
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

int	simulation_stops(t_philo *philo, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		if (philo[i].eat_time < philo[i].times_must_eat)
		{
			return (0);
		}
		if (philo[i].times_must_eat == -1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_printf(int time, int num, char *str, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%d %d ", time, num + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(print);
}

void	destroy_mutex(pthread_mutex_t *forks, pthread_mutex_t print, int num_forks)
{
	int	i;

	i = 0;
	while (i < num_forks)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&print);
}	

void	ft_exit(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t print, int num)
{
	free(philo);
	destroy_mutex(forks, print, num);
	free(forks);
}
