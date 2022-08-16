/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:32:49 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 16:06:44 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timeset	*validator(int ac, char **av)
{
	int			nop;
	int			ttd;
	int			tts;
	int			tte;
	t_timeset	*set;

	if (ac != 5 && ac != 6)
		exit_error("Check number of arguments\n");
	nop = int_conversion(av[1]);
	ttd = int_conversion(av[2]);
	tts = int_conversion(av[3]);
	tte = int_conversion(av[4]);
	set = init_timeset(ttd, tte, tts, nop);
	return (set);
}
