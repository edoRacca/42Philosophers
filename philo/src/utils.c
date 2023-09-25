/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:53:33 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/24 12:27:44 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Checks the len of the string
// Own version of atoi

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;
	int	ris;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	neg = 1;
	if (s[i] == '-')
		neg = -1;
	if (neg == -1 || s[i] == '+')
		i++;
	ris = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ris = (ris * 10) + (s[i] - '0');
		i++;
	}
	return (ris * neg);
}

long	ft_atol(char *s)
{
	int		i;
	int		neg;
	long	ris;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	neg = 1;
	if (s[i] == '-')
		neg = -1;
	if (neg == -1 || s[i] == '+')
		i++;
	ris = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ris = (ris * 10) + (s[i] - '0');
		i++;
	}
	return (ris * neg);
}

// Improved version of sleep function

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

// Gets the current time in milliseconds

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
