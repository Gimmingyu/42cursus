/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:48 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 15:44:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(char *str)
{
	if (!str)
		exit(1);
	printf("%s\n", str);
	exit(1);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && 13 >= c))
		return (1);
	return (0);
}

int	int_conversion(char *str)
{
	size_t		idx;
	long long	nbr;
	int			sign;

	nbr = 0;
	idx = 0;
	sign = 1;
	while (str[idx] && ft_isspace(str[idx]) == 1)
		idx++;
	if (str[idx] == '-')
		sign = -1;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	while (str[idx] && '0' <= str[idx] && str[idx] <= '9')
	{
		nbr = (nbr * 10) + (str[idx] - '0');
		if (nbr > 2147483647 && sign == 1)
			exit_error("Not in range of integer\n");
		else if (nbr > 2147483648 && sign == -1)
			exit_error("Not in range of integer\n");
		idx++;
	}
	return (sign * nbr);
}
