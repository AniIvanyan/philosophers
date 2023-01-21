/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:15:01 by zkarapet          #+#    #+#             */
/*   Updated: 2023/01/22 02:13:19 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s && s[count])
		count++;
	return (count);
}

int	ft_atoi(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	if (sign * number > INT_MAX || sign * number < INT_MIN
		|| sign * number < 0)
		return (-1);
	return (sign * number);
}

int	ft_isnumber(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
		while (j < len)
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int	checking_parse_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	if (!ft_isnumber(argc, argv))
		return (1);
	if (ft_atoi(argv[i]) == 0)
		return (1);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}
