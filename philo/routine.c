/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:32:29 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/22 20:09:54 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->checker->ate_at = get_current_time();
	philo->checker->started_at = get_current_time();
	if (philo->id % 2)
		usleep(philo->condition->tte * 1000);
	while (philo->condition->is_finished == FALSE)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(200);
	}
	return (NULL);
}
