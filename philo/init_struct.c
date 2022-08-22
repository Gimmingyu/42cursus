/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:59:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/22 20:12:21 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosopher(t_condition *condition, t_checker *checker)
{
	t_philo	*philos;
	int		idx;

	philos = malloc(sizeof(t_philo) * condition->nop);
	if (!philos)
		exit_error("Memory allocate error");
	idx = -1;
	while (++idx < condition->nop)
	{
		philos[idx].condition = condition;
		philos[idx].checker = &checker[idx];
		philos[idx].left = idx;
		philos[idx].right = (idx + 1) % condition->nop;
		philos[idx].id = idx;
	}
	return (philos);
}

t_checker	*init_checker(int nop)
{
	t_checker	*checker;
	int			idx;

	checker = malloc(sizeof(t_checker) * nop);
	if (!checker)
		exit_error("Memory allocate error");
	idx = -1;
	while (++idx < nop)
	{
		checker[idx].started_at = 0;
		checker[idx].ate_at = 0;
		checker[idx].died_at = 0;
		checker[idx].personal_eat_cnt = 0;
	}
	return (checker);
}

t_condition	*init_condition(int *array)
{
	t_condition		*condition;
	int				idx;

	condition = malloc(sizeof(t_condition));
	if (!condition)
		exit_error("Memory allocate error");
	condition->mutex = malloc(sizeof(pthread_mutex_t) * array[0]);
	if (!condition->mutex)
		exit_error("Memory allocate error");
	idx = -1;
	while (++idx < array[0])
		if (pthread_mutex_init(&(condition->mutex[idx]), NULL))
			exit_error("Mutex init error");
	if (pthread_mutex_init(&(condition->print), NULL))
		exit_error("Mutex init error");
	condition->nop = array[0];
	condition->lifetime = array[1];
	condition->tte = array[2];
	condition->tts = array[3];
	condition->must_eat = array[4];
	condition->is_finished = FALSE;
	condition->finished_philo_cnt = 0;
	return (condition);
}
