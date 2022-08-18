/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:00:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/18 16:36:32 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && 13 >= c))
		return (1);
	return (0);
}

static int	int_conversion(char *str)
{
	long		nbr;
	int			sign;
	ssize_t		i;

	if (!str)
		exit_error("Found NULL pointer");
	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1))
			exit_error("Not in range of integer");
		i++;
	}
	return (sign * nbr);
}

void	validator(int ac, char **av, t_condition **ptr)
{
	int	arr[5];

	arr[0] = int_conversion(av[1]);
	arr[1] = int_conversion(av[2]);
	arr[2] = int_conversion(av[3]);
	arr[3] = int_conversion(av[4]);
	if (ac == 6)
		arr[4] = int_conversion(av[5]);
	*ptr = init_condition(arr);
}

void	free_structs(t_philo *philo)
{
	free(philo->checker);
	free(philo->condition);
	free(philo);
}
