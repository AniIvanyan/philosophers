/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:33 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/19 00:53:26 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//lock left
// printf has taken left fork
//lock right
//print has taken right fork
//print eating
//my_usleep(time to eat)
//unlock left
//unlock right
// print is sleeping
// my_usleep(time to sleep)
// print is thinking

void	*philos(void *data)
{
	t_philo			*philo;
	pthread_mutex_t	print;
	 
	philo = (t_philo *)data;
	pthread_mutex_init(&print, NULL);
	if (philo->philo_num % 2 == 0)
		ft_usleep(2500);
	while (1)
	{
		pthread_mutex_lock(philo->left);
		ft_printf(getting_time(), philo->philo_num, "has taken the left fork", &print);
		pthread_mutex_lock(philo->right);
		ft_printf(getting_time(), philo->philo_num, "has taken the right fork", &print);
		ft_printf(getting_time(), philo->philo_num, "is eating", &print);
		philo->last_eat_time = getting_time();
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		ft_printf(getting_time(), philo->philo_num, "is sleeping", &print);
		ft_usleep(philo->time_to_sleep);
		ft_printf(getting_time(), philo->philo_num, "is thinking", &print);
	}
	pthread_mutex_destroy(&print);
}