/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:35:29 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/22 00:27:14 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	philo_initializer(t_philo *philo, int i, char **argv)
{
	philo[i].philo_num = i;
	philo[i].time_to_die = ft_atoi(argv[2]);
	philo[i].time_to_eat = ft_atoi(argv[3]);
	philo[i].time_to_sleep = ft_atoi(argv[4]);
	philo[i].times_must_eat = -1;
	if (argv[5])
		philo[i].times_must_eat = ft_atoi(argv[5]);
	philo[i].last_eat_time = 0;
	philo[i].eat_time = 0;
}

int	main(int argc, char **argv)
{
	int				i;
	int				num_of_philos;
	int				start;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;

	if (checking_parse_error(argc, argv))
	{
		printf("Invalid input detected\n");
		return (0);
	}
	num_of_philos = ft_atoi(argv[1]);
	if (num_of_philos == 1)
	{
		printf("0 1 died\n");
		return (0);
	}
	start = getting_time();
	i = -1;
	philo = malloc(num_of_philos * (sizeof(t_philo)));
	forks = malloc(num_of_philos * (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&print, NULL); 
	while (++i < num_of_philos)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < num_of_philos)
	{
		philo_initializer(philo, i, argv);
		philo[i].left = &forks[i];
		philo[i].right = &forks[(i + 1) % num_of_philos];
		philo[i].start = start;
		philo[i].print = &print;
	}
	i = -1;
	while (++i < num_of_philos)
		pthread_create(&philo[i].id, NULL, philos, (void *)&philo[i]);
	i = -1;
	while (++i < num_of_philos)
		pthread_detach(philo[i].id);
	while (1)
	{
		i = -1;
		while (++i < num_of_philos)
		{
			if (is_died(&philo[i]))
			{
				printf("%d %d died\n", getting_time() - philo[i].start, i + 1);
				ft_exit(philo, forks, print, num_of_philos);
				return (0);
			}
		}
		if (simulation_stops(philo, num_of_philos))
		{
			printf("simulation stopped\n");
			return (0);
		}
	}
}
