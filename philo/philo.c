/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:00:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/18 16:41:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	free_structs(philo);
	system("leaks philo");
	return (0);
}
