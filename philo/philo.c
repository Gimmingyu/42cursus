/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:07:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/26 17:58:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_thread(t_philo *philo)
{
	int		idx;
	pid_t	pid;

	idx = -1;
	while (++idx < philo->info->num_of_philos)
	{
		pid = fork();
		if (pid == -1)
			exit_error("Fork Failed Error");
		else if (pid == 0)
			continue ;
		else
		{
			philo[idx].checker->pid = pid;
			if (pthread_create(&(philo[idx].thread), NULL, \
								start_routine, &(philo[idx])))
				exit_error("pthread_create error");
			break ;
		}
	}
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
