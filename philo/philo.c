/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:00:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/22 20:13:43 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_structs(t_philo *philo)
{
	pthread_mutex_destroy(philo->condition->mutex);
	free(philo->checker);
	free(philo->condition);
	free(philo);
}

void	monitoring(t_philo *philo)
{
	int	idx;
	int	remain;

	while (philo->condition->is_finished == FALSE)
	{
		if (philo->condition->must_eat != 0 && \
			philo->condition->finished_philo_cnt >= philo->condition->nop)
		{
			philo->condition->is_finished = TRUE;
			break ;
		}
		idx = -1;
		while (++idx < philo->condition->nop)
		{
			remain = get_current_time() - philo[idx].checker->ate_at;
			if (remain >= philo->condition->lifetime)
			{
				logger(philo, philo->id, "is died");
				philo->condition->is_finished = TRUE;
				break ;
			}
			usleep(100);
		}
		usleep(100);
	}
}

void	create_thread(t_philo *philo)
{
	int	idx;
	int	flag;

	idx = -1;
	while (++idx < philo->condition->nop)
	{
		flag = pthread_create(&philo[idx].thread, NULL, start_routine, &philo[idx]);
		if (flag)
			exit_error("pthread_create failed");
		usleep(100);
	}
	monitoring(philo);
	idx = -1;
	while (++idx < philo->condition->nop)
		pthread_join(philo[idx].thread, NULL);
}

int	main(int ac, char **av)
{
	t_condition	*condition;
	t_checker	*checker;
	t_philo		*philo;

	if (ac != 5 && ac != 6)
		return (0);
	validator(ac, av, &condition);
	checker = init_checker(condition->nop);
	philo = init_philosopher(condition, checker);
	create_thread(philo);
	free_structs(philo);
	return (0);
}
