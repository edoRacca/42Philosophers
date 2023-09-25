/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:26:42 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/25 10:43:59 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse(int ac, char *av[])
{
	if (ft_atol(av[1]) < 1 || ft_atol(av[2]) < 0 || ft_atol(av[3]) < 0
		|| ft_atol(av[4]) < 0 || ft_atol(av[1]) > PHILO_MAX
		|| ft_atol(av[2]) > MAX_INT || ft_atol(av[4]) > MAX_INT)
		return (1);
	if (ac == 6)
	{
		if (ft_atol(av[5]) < 0 || ft_atol(av[5]) > MAX_INT)
			return (1);
	}
	return (0);
}
