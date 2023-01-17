/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:37:25 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/18 03:00:11 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t			id;
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	int					last_eat_time;
	int					must_die;
}	t_philo;


//utils.c
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_atoi(const char *str);

//philo.c
void	*philos(void *data);
#endif