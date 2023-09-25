/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:04:35 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/24 11:37:53 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_die(char *str)
{
	printf("%s\n", str);
	return (1);
}

// Main function
int	main(int ac, char *av[])
{
	t_general		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac < 5 || ac > 6)
		return (ft_die("ERROR: Invalid argument number."));
	if (parse(ac, av) == 1 || check_args(av) == 1)
		return (ft_die("Invalid arguments"));
	init_program(&program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
	create_threads(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
