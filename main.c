/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:08:29 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/25 18:08:32 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initializer1(t_philo *philo, int num, int start, char **argv)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		philo[i].num = i;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		philo[i].times_must_eat = -1;
		if (argv[5])
			philo[i].times_must_eat = ft_atoi(argv[5]);
		philo[i].last_eat_time = 0;
		philo[i].eat_time = 0;
		philo[i].s = start;
	}
}

void	initializer2(t_philo *p, pthread_mutex_t *f, pthread_mutex_t *pr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		p[i].left = &f[i];
		p[i].right = &f[(i + 1) % n];
		p[i].p = pr;
	}
}

int	main_process(int num, t_philo *p, pthread_mutex_t *f, pthread_mutex_t pr)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < num)
		{
			if (is_died(&p[i]))
			{
				printf("%d %d died\n", get_time() - p[i].s, i + 1);
				ft_exit(p, f, pr, num);
				return (0);
			}
		}
		if (simulation_stops(p, num))
		{
			printf("simulation stopped\n");
			ft_exit(p, f, pr, num);
			return (0);
		}
	}
	return (1);
}

int	checking(char **argv, int argc)
{
	if (checking_parse_error(argc, argv))
	{
		printf("Invalid input detected\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 died\n");
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
	{
		printf("simulation stopped\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				i;
	int				start;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;

	start = get_time();
	if (!checking(argv, argc))
		return (0);
	i = -1;
	philo = malloc(ft_atoi(argv[1]) * (sizeof(t_philo)));
	forks = malloc(ft_atoi(argv[1]) * (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&print, NULL);
	while (++i < ft_atoi(argv[1]))
		pthread_mutex_init(&forks[i], NULL);
	initializer1(philo, ft_atoi(argv[1]), start, argv);
	initializer2(philo, forks, &print, ft_atoi(argv[1]));
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_create(&philo[i].id, NULL, philos, (void *)&philo[i]);
	i = -1;
	while (++i < ft_atoi(argv[1]))
		pthread_detach(philo[i].id);
	main_process(ft_atoi(argv[1]), philo, forks, print);
}
