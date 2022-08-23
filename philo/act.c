/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:59:48 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/23 17:06:42 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logger(t_philo *philo, int id, const char *str)
{
	pthread_mutex_lock(&philo->condition->print);
	if (philo->condition->is_finished == FALSE)
		printf("%ld %d %s\n", \
		(get_current_time() - philo->checker->started_at) / 1000, \
				id, str);
	pthread_mutex_unlock(&philo->condition->print);
}

void	timer(unsigned long wait_time)
{
	unsigned long	t;

	t = wait_time + get_current_time();
	while (t > get_current_time())
		usleep(50);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->condition->mutex[philo->left]));
	logger(philo, philo->id, "has taken a fork");
	if (philo->condition->nop != 1)
	{
		pthread_mutex_lock(&(philo->condition->mutex[philo->right]));
		logger(philo, philo->id, "has taken a fork");
		logger(philo, philo->id, "is eating");
		timer(philo->condition->tte);
		philo->checker->ate_at = get_current_time();
		philo->checker->personal_eat_cnt++;
		if (philo->checker->personal_eat_cnt == philo->condition->must_eat)
			philo->condition->finished_philo_cnt++;
		pthread_mutex_unlock(&(philo->condition->mutex[philo->right]));
	}
	pthread_mutex_unlock(&(philo->condition->mutex[philo->left]));
}

void	philo_sleep(t_philo *philo)
{
	logger(philo, philo->id, "is sleeping");
	timer(philo->condition->tts);
}

void	philo_think(t_philo *philo)
{
	logger(philo, philo->id, "is thinking");
}
