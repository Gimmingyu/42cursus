/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:27:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/26 17:59:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	even_philosopher_must_sleep(t_philo *philo)
{
	if (philo->checker->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
}

// static void	forked_philosopher(t_philo *philo)
// {
// }

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	even_philosopher_must_sleep(philo);
	printf("philos id = %d\n", philo->checker->id);
	printf("philos pid =  %d\n", (int)philo->checker->pid);
	// forked_philosopher(philo);
	return (NULL);
}
