/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:07:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 16:09:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_thread(t_philo *philo)
{
	int	idx;

	idx = -1;
	while (++idx < philo->info->num_of_philos)
		if (pthread_create(&(philo[idx].thread), NULL, \
							start_routine, &(philo[idx])))
			exit_error("pthread_create error");
	idx = -1;
	while (++idx < philo->info->num_of_philos)
		pthread_join(philo[idx].thread, NULL);
}

int	main(int ac, char **av)
{
	t_info		*info;
	t_philo		*philo;

	sem_unlink("forks");
	info = init_information();
	validator(ac, av, info);
	philo = init_philo(info);
	create_thread(philo);
	free_structs(philo);
	return (0);
}
