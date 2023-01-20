/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:35:29 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/20 07:01:40 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	philo_initializer(t_philo *philo, int i, char **argv, int argc)
{
	philo[i].philo_num = i;
	philo[i].time_to_die = ft_atoi(argv[2]) * 1000;
	philo[i].time_to_eat = ft_atoi(argv[3]) * 1000;
	philo[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		philo[i].times_must_eat = ft_atoi(argv[5]);
	else
		philo[i].times_must_eat = -1;
	philo[i].last_eat_time = 0;
}

int	main(int argc, char **argv)
{
	int				i;
	int				num_of_philos;
	int				start;
	t_philo			*philo;
	pthread_mutex_t	*forks;


	if (argc != 5 && argc != 6)
	{
		//TODO
		printf("Too many arguments");
		return (0);
	}
	start = getting_time();
	i = -1;
	num_of_philos = ft_atoi(argv[1]);
	philo = malloc(num_of_philos * (sizeof(t_philo)));
	forks = malloc(num_of_philos * (sizeof(pthread_mutex_t)));
	while (++i < num_of_philos)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < num_of_philos)
	{
		philo_initializer(philo, i, argv, argc);
		philo[i].left = &forks[i];
		philo[i].right = &forks[(i + 1) % num_of_philos];
		philo[i].start = start;
	}
	i = -1;
	while (++i < num_of_philos)
		pthread_create(&philo[i].id, NULL, philos,(void *)&philo[i]);
	i = -1;
	while (++i < num_of_philos)
		pthread_detach(philo[i].id);
	while (1)
	{
		i = -1;
		while (++i < num_of_philos)
			if (is_died(&philo[i]))
			{	
				printf("hello\n");
				exit(0);
			}
				//return (0);
	}
}

