/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:26:47 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 16:37:35 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_status;

typedef struct s_timeset
{
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	number_of_philos;
}	t_timeset;

/******************************************
 ******* Functions for validate arg *******
*******************************************/
t_timeset	*validator(int ac, char **av);

/*****************************************
 ******* Functions for init struct *******
******************************************/
t_timeset	*init_timeset(int ttd, int tte, int tts, int nop);

/*****************************************
 ********* Functions for utility *********
******************************************/
void		exit_error(char *str);
int			int_conversion(char *str);

/**********************************************
 ********* Functions for print status *********
***********************************************/
void		print_status(t_status status);

#endif
