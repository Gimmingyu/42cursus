/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:31:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 16:50:05 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		philo->checker->is_finished = TRUE;
		exit_error("Fork error");
	}
	if (pid)
	{
		waitpid(pid, NULL, WNOHANG);
		
	}
	else
	{
		philo->checker->is_finished = TRUE;
		philo->checker->start_at = 9999;
		printf("philo id = %d\n", philo->checker->id);
		printf("pointer of philo = %p\n", philo);
	}
}

// void	philo_sleep(t_philo *philo)
// {
// 	;
// }

// void	philo_think(t_philo *philo)
// {
// 	;
// }
