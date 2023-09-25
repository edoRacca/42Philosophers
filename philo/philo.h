/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:52:20 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/25 10:43:27 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200
# define MAX_INT 2147483647

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_general
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_general;

// actions.c
void				think(t_philo *philo);
void				nap(t_philo *philo);
void				eat(t_philo *philo);

// checker.c
int					philosopher_dead(t_philo *philos, size_t time_to_die);
int					check_death(t_philo *philos);
int					check_eaten(t_philo *philos);
void				*checker_routine(void *p);

// destroy.c
int					ft_strlen(char *str);
void				destory_all(char *str, t_general *program,
						pthread_mutex_t *forks);

// init.c
void				init_input(t_philo *philo, char *av[]);
void				init_philos(t_philo *philos, t_general *program,
						pthread_mutex_t *forks, char *av[]);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_program(t_general *program, t_philo *philos);

// main.c
int					ft_die(char *str);

// parse.c
int					check_args(char *av[]);
int					parse(int ac, char *av[]);

// threads.c
int					dead_loop(t_philo *philos);
void				*philo_routine(void *p);
int					create_threads(t_general *program, pthread_mutex_t *forks);

// utils.c
int					ft_atoi(const char *s);
long				ft_atol(char *s);
int					ft_usleep(size_t milliseconds);
size_t				get_current_time(void);
void				print_message(char *str, t_philo *philo, int id);

#endif
