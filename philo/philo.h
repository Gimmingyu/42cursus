/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:06:38 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 16:40:34 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/stat.h> 
# include <signal.h>

# define TRUE 1
# define FALSE 0

typedef struct s_information
{
	int		num_of_philos;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		must_eat;
	sem_t	*sem;
	sem_t	*print_sem;
}	t_info;

typedef struct s_checker
{
	unsigned long	start_at;
	unsigned long	ate_at;
	int				eat_count;
	int				is_finished;
	int				id;
}	t_checker;

typedef struct philosophers
{
	t_info			*info;
	t_checker		*checker;
	pthread_t		thread;
}	t_philo;

void		*start_routine(void *arg);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

t_info		*init_information(void);
t_checker	*init_checker(int id);
t_philo		*init_philo(t_info *info);

void		validator(int ac, char **av, t_info *info);
void		exit_error(const char *str);
void		free_structs(t_philo *philo);

#endif