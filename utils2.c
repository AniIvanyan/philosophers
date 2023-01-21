/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:04:08 by zkarapet          #+#    #+#             */
/*   Updated: 2023/01/22 02:09:45 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	destroy_mutex(pthread_mutex_t *f, pthread_mutex_t p, int num)
{
	int	i;

	i = 0;
	while (i < num)
		pthread_mutex_destroy(&f[i++]);
	pthread_mutex_destroy(&p);
}

void	ft_exit(t_philo *philo, pthread_mutex_t *f, pthread_mutex_t p, int num)
{
	free(philo);
	destroy_mutex(f, p, num);
	free(f);
}
