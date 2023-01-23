/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:33 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/22 03:01:26 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (p->num % 2 == 0)
		ft_usleep(200);
	while (1)
	{
		pthread_mutex_lock(p->left);
		ft_printf(get_time() - p->s, p->num, "has taken the left fork", p->p);
		pthread_mutex_lock(p->right);
		ft_printf(get_time() - p->s, p->num, "has taken the right fork", p->p);
		ft_printf(get_time() - p->s, p->num, "is eating", p->p);
		if (p->times_must_eat != -1)
			p->eat_time++;
		p->last_eat_time = get_time();
		ft_usleep(p->time_to_eat);
		pthread_mutex_unlock(p->right);
		pthread_mutex_unlock(p->left);
		ft_printf(get_time() - p->s, p->num, "is sleeping", p->p);
		ft_usleep(p->time_to_sleep);
		ft_printf(get_time() - p->s, p->num, "is thinking", p->p);
	}
}
