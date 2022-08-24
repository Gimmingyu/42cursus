/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:35:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 15:57:43 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*init_information(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		exit_error("Memory Allocation Error");
	info->must_eat = 0;
	info->num_of_philos = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	return (info);
}

t_checker	*init_checker(int id)
{
	t_checker	*checker;

	checker = malloc(sizeof(t_checker));
	if (!checker)
		exit_error("Memory Allocation Error");
	checker->id = id;
	checker->ate_at = 0;
	checker->start_at = 0;
	checker->is_finished = FALSE;
	checker->eat_count = 0;
	return (checker);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		id;

	philo = malloc(sizeof(t_philo) * info->num_of_philos);
	if (!philo)
		exit_error("Memory Allocation Error");
	id = -1;
	while (++id < info->num_of_philos)
	{
		(&philo[id])->checker = init_checker(id);
		(&philo[id])->info = info;
	}
	return (philo);
}
