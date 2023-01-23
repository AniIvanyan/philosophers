/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:37:25 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/24 00:44:34 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	pthread_t			id;
	int					num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_mutex_t		*p;
	int					last_eat_time;
	int					s;
	int					eat_time;
}	t_philo;

//utils.c
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		get_time(void);
void	ft_usleep(int ms);

//utils2.c
int		is_died(t_philo *philo);
void	ft_printf(int time, int num, char *str, pthread_mutex_t *print);
int		simulation_stops(t_philo *philo, int num_philos);
void	destroy_mutex(pthread_mutex_t *f, pthread_mutex_t p, int num);
void	ft_exit(t_philo *philo, pthread_mutex_t *f, pthread_mutex_t p, int num);

//philo.c
void	*philos(void *data);

//parsing.c
int		ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_isnumber(int argc, char **argv);
int		checking_parse_error(int argc, char **argv);
#endif
