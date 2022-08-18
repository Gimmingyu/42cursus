/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:59:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/18 16:34:25 by mingkim          ###   ########.fr       */
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
		philos[idx].condition = &condition[idx];
		philos[idx].checker = &checker[idx];
		philos[idx].left = 0;
		philos[idx].right = 0;
		philos[idx].thread = NULL;
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
		checker[idx].ate_at = 0;
		checker[idx].died_at = 0;
		checker[idx].ate_at = 0;
		checker[idx].total_eat_cnt = 0;
		checker[idx].is_finished = FALSE;
	}
	return (checker);
}

t_condition	*init_condition(int *array)
{
	t_condition	*condition;
	int			idx;

	condition = malloc(sizeof(t_condition) * array[0]);
	if (!condition)
		exit_error("Memory allocate error");
	idx = -1;
	while (++idx < array[0])
	{
		condition[idx].nop = array[0];
		condition[idx].lifetime = array[1];
		condition[idx].tte = array[2];
		condition[idx].tts = array[3];
		if (array[0] == 6)
			condition[idx].must_eat = array[4];
	}
	return (condition);
}
