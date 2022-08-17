/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:52:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/17 19:47:05 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

t_condition	*init_condition(int ttd, int tte, int tts, int nop)
{
	t_condition	*condition;
	size_t		idx;

	condition = malloc(sizeof(t_condition));
	if (!condition)
		exit_error("Memory allocate error\n");
	condition->time_to_die = ttd;
	condition->time_to_eat = tte;
	condition->time_to_sleep = tts;
	condition->number_of_philos = nop;
	condition->fork = malloc(sizeof(pthread_mutex_t) * condition->number_of_philos);
	if (!condition->fork)
		exit_error("Memory allocate error\n");
	idx -1;
	while (++idx < condition->number_of_philos)
		if (pthread_mutex_init(&condition->fork[idx], NULL))
			exit_error("Mutex init Failed\n");
	if (pthread_mutex_init(&condition->print, NULL))
		exit_error("Mutex init Failed\n");
	return (condition);
}

t_checker	*init_checker()
{
	t_checker	*checker;

	checker = malloc(sizeof(t_checker));
	if (!checker)
		exit_error("Memory allocate error\n");
	checker->start_time = 0;
	checker->eat_time = 0;
	checker->cnt = 0;
	checker->finish = 0;
	checker->finished_eat_cnt = 0;
	return (checker);
}


// Where is pthread_t ???
t_philo	*init_philo(t_condition *condition, t_checker *checker)
{
	t_philo	*philo;
	size_t	idx;

	philo = malloc(sizeof(t_philo) * condition->number_of_philos);
	if (!philo)
		exit_error("Memory allocate error\n");
	idx = -1;
	while (++idx < condition->number_of_philos)
	{
		philo[idx].id = idx;
		philo[idx].left = idx;
		philo[idx].right = (idx + 1) % condition->number_of_philos;
		philo[idx].checker = checker;
		philo[idx].condition = condition;
	}
	return (philo);
}
