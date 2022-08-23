/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:26:47 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/23 16:26:23 by mingkim          ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_status;

// 문제의 조건을 설정하는 구조체
typedef struct s_condition
{
	int				tte;
	int				tts;
	int				nop;
	int				lifetime;
	int				must_eat;
	int				is_finished;
	int				finished_philo_cnt;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
}	t_condition;

// 각 철학자의 현 상태를 담는다.
typedef struct s_checker
{
	int				personal_eat_cnt;
	unsigned long	started_at;
	unsigned long	ate_at;
	unsigned long	died_at;
}	t_checker;

// condition, checker 및 각 철학자의 현 상태와 thread 정보를 담는 구조체
typedef struct s_philo
{
	t_condition	*condition;
	t_checker	*checker;
	pthread_t	thread;
	int			left;
	int			right;
	int			id;
}	t_philo;

void			exit_error(char *str);
void			validator(int ac, char **av, t_condition **ptr);
unsigned long	get_current_time(void);

t_condition		*init_condition(int *array);
t_checker		*init_checker(int nop);
t_philo			*init_philosopher(t_condition *condition, t_checker *checker);

void			*start_routine(void *arg);

void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

void			logger(t_philo *philo, int id, const char *str);
void			timer(unsigned long wait_time);
#endif
