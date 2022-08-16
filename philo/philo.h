/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:26:47 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 22:47:10 by gimmingyu        ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_status;

typedef struct s_condition
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_philos;
	int				must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_condition;

typedef struct s_checker
{
	unsigned long	start_time;
	unsigned long	eat_time;
	int				finish;
	int				finished_eat_cnt;
	int				cnt;
}	t_checker;

typedef struct s_philo
{
	t_condition		*condition;
	t_checker		*checker;
	pthread_t		p_thread;
	int				id;
	int				left;
	int				right;
}	t_philo;

/******************************************
 ******* Functions for validate arg *******
*******************************************/
t_condition	*validator(int ac, char **av);

/*****************************************
 ******* Functions for init struct *******
******************************************/
t_condition	*init_condition(int ttd, int tte, int tts, int nop);
t_checker	*init_checker();
t_philo		*init_philo(t_condition *condition, t_checker *checker);

/*****************************************
 ********* Functions for utility *********
******************************************/
void		exit_error(char *str);

/**********************************************
 ********* Functions for print status *********
***********************************************/
void		print_status(t_status status);

#endif
