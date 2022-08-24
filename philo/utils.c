/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:12:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/24 16:30:42 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(const char *str)
{
	printf("%s\n", str);
	exit(1);
}

static int	int_conversion(char *str)
{
	size_t	idx;
	long	nbr;
	int		sign;

	idx = 0;
	nbr = 0;
	sign = 1;
	while (str[idx] && (str[idx] == 32 || (9 <= str[idx] && str[idx] <= 13)))
		idx++;
	if (str[idx] && (str[idx] == '-'))
		sign = -1;
	if (str[idx] && (str[idx] == '+' || str[idx] == '-'))
		idx++;
	while (str[idx])
	{
		if (str[idx] && (str[idx] < '0' || '9' < str[idx]))
			exit_error("Not a numeric argument");
		nbr = (nbr * 10) + (str[idx] - '0');
		if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1))
			exit_error("Not in range of integer");
		idx++;
	}
	return (nbr * sign);
}

void	validator(int ac, char **av, t_info *info)
{
	if (ac != 5 && ac != 6)
		exit_error("Invalid number of args");
	info->num_of_philos = int_conversion(av[1]);
	info->time_to_die = int_conversion(av[2]);
	info->time_to_eat = int_conversion(av[3]);
	info->time_to_sleep = int_conversion(av[4]);
	info->must_eat = 0;
	if (ac == 6)
		info->must_eat = int_conversion(av[5]);
	info->sem = sem_open("forks", O_CREAT | O_EXCL, 0644, \
								info->num_of_philos);
	if (info->sem == SEM_FAILED)
		exit_error("SEM FAILED");
}

void	free_structs(t_philo *philo)
{
	free(philo->info);
	free(philo->checker);
	free(philo);
	sem_close(philo->info->sem);
	sem_unlink("forks");
	exit(0);
}
