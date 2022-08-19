/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:00:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/19 14:13:18 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func1(void *arg)
{
	t_philo	*philo;
	int		idx;

	philo = (t_philo *)arg;
	pthread_mutex_init(philo->condition->mutex, NULL);
	usleep(100);
	idx = -1;
	while (++idx < philo->condition->nop)
	{
		printf("idx = %d\n", idx);
		usleep(100);
	}
	usleep(100);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_condition	*condition;
	t_checker	*checker;
	t_philo		*philo;
	int			idx;

	if (ac != 5 && ac != 6)
		return (0);
	validator(ac, av, &condition);
	checker = init_checker(condition->nop);
	philo = init_philosopher(condition, checker);
	idx = -1;
	while (++idx < philo->condition->nop)
		pthread_create(&philo[idx].thread, NULL, &func1, &philo[idx]);
	idx = -1;
	while (++idx < philo->condition->nop)
		pthread_join(philo[idx].thread, NULL);
	free_structs(philo);
	system("leaks philo");
	return (0);
}
