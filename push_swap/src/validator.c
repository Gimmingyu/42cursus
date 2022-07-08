/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:28:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/08 16:09:18 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_integer(char *str)
{
	size_t	idx;
	size_t	len;

	if (!str)
		response_error();
	idx = 0;
	len = ft_strlen(str);
	if ((str[0] != '-' && str[0] != '+') && (str[0] <= '0' || str[0] > '9'))
		response_error();
	if (str[0] == '-' || str[0] == '+')
		idx++;
	while (str[idx] && idx < len)
	{
		if (str[idx] && (str[idx] < '0' || str[idx] > '9'))
			response_error();
		idx++;
	}
	return (OK);
}

void	check_is_integer(int ac, char **av)
{
	int			idx;
	long long	nbr;

	idx = 0;
	while (++idx < ac && av[idx])
	{
		is_integer(av[idx]);
		a_to_longlong(av[idx]);
	}
}

void	check_is_duplicate(int ac, char **av)
{
	int	idx;
	int	sub_idx;

	idx = 0;
	while (++idx < ac && av[idx])
	{
		sub_idx = 0;
		while (++sub_idx < idx)
			if (av[sub_idx] == av[idx])
				response_error();
	}
}

void	validator(int ac, char **av)
{
	if (ac == 1)
		response_error();
	check_is_integer(ac, av);
	check_is_duplicate(ac, av);
}
