/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:28:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 19:14:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_integer(char *str)
{
	ssize_t	idx;
	ssize_t	len;

	if (!str)
		response_error();
	idx = 0;
	len = ft_strlen(str);
	if ((str[0] != '-' && str[0] != '+') && (str[0] < '0' || str[0] > '9'))
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

int	check_duplicate(char **str)
{
	ssize_t	idx;
	ssize_t	sub_idx;

	if (!str)
		response_error();
	idx = 0;
	while (str[++idx])
	{
		sub_idx = -1;
		while (++sub_idx < idx)
			if (str[sub_idx] == str[idx])
				response_error();
	}
	return (OK);
}

void	validator(int ac, char **av, \
					t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	char	**temp;
	ssize_t	idx;
	ssize_t	temp_idx;
	int		sign;

	if (ac == 1 || !av || !a_stack || !b_stack)
		response_error();
	idx = 0;
	while (++idx < ac)
	{
		temp = ft_split(av[idx], ' ');
		temp_idx = -1;
		if (!temp)
			response_error();
		while (temp[++temp_idx])
		{
			if (is_integer(temp[temp_idx]) == ERROR || \
				check_duplicate(temp) == ERROR)
				response_error();
			push_bottom(a_stack, a_to_longlong(temp[temp_idx]), 0);
		}
		ft_malloc_error(temp);
	}
}
