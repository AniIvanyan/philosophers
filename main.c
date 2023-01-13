/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:35:29 by aivanyan          #+#    #+#             */
/*   Updated: 2023/01/14 03:46:23 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_initialize(t_args *args, char **argv, int argc)
{
	args->num_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->times_must_eat = ft_atoi(argv[5]);
}
int	main(int argc, char **argv)
{
	t_args	*args;
	int		i;
	pthread_t	id;

	i = 0;
	args = malloc(sizeof(t_args));
	if (argc != 5 && argc != 6)
		return (1);
	args_initialize(args, argv, argc);
	while (i++ < args->num_of_philos)
		pthread_create(&id, NULL, philo, NULL);
}