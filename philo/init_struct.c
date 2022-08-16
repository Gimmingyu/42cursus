/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:52:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 15:54:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timeset	*init_timeset(int ttd, int tte, int tts, int nop)
{
	t_timeset	*set;

	set = malloc(sizeof(t_timeset));
	if (!set)
		exit_error("Memory allocate error\n");
	set->time_to_die = ttd;
	set->time_to_eat = tte;
	set->time_to_sleep = tts;
	set->number_of_philos = nop;
	return (set);
}
