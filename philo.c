/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:33 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/18 01:54:44 by aivanyan         ###   ########.fr       */
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
	t_philo	*philo;
	 
	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(philo->left);
		printf("Left fork is taken");
		pthread_mutex_lock(philo->right);
		printf("Right fork is taken");
		printf("is eating");
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		printf("is sleeping");
		usleep(philo->time_to_sleep);
		printf("is thinking");
	}
}