/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:53:26 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/24 11:52:29 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Checks if the philosopher is dead
int	philosopher_dead(t_philo *philos, size_t time_to_die)
{
	pthread_mutex_lock(philos->meal_lock);
	if (get_current_time() - philos->last_meal >= time_to_die
		&& philos->eating == 0)
		return (pthread_mutex_unlock(philos->meal_lock), 1);
	pthread_mutex_unlock(philos->meal_lock);
	return (0);
}

// Check if any philo died

int	check_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals
int	check_eaten(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

// Monitor thread routine
void	*checker_routine(void *p)
{
	t_philo	*philos;

	philos = (t_philo *)p;
	while (1)
		if (check_death(philos) == 1 || check_eaten(philos) == 1)
			break ;
	return (p);
}
