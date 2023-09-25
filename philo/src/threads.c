/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:20:46 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/24 11:34:46 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Checks if the value of dead_flag changed

int	dead_loop(t_philo *philos)
{
	pthread_mutex_lock(philos->dead_lock);
	if (*philos->dead == 1)
		return (pthread_mutex_unlock(philos->dead_lock), 1);
	pthread_mutex_unlock(philos->dead_lock);
	return (0);
}

// Thread routine

void	*philo_routine(void *p)
{
	t_philo	*philos;

	philos = (t_philo *)p;
	if (philos->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philos))
	{
		eat(philos);
		nap(philos);
		think(philos);
	}
	return (p);
}

// Creates all the threads

int	create_threads(t_general *program, pthread_mutex_t *forks)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, &checker_routine, program->philos) != 0)
		destory_all("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].philo_thread, NULL,
				&philo_routine, &program->philos[i]) != 0)
			destory_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		destory_all("Thread join error", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].philo_thread, NULL) != 0)
			destory_all("Thread join error", program, forks);
		i++;
	}
	return (0);
}
