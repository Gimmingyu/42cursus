/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:27:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 16:39:22 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		fork;

	philo = (t_philo *)arg;
	fork = 0;
	if (philo->checker->id % 2)
		usleep(philo->info->time_to_eat * 1000);
	while (philo->checker->is_finished == FALSE)
		philo_eat(philo);
	return (NULL);
}
