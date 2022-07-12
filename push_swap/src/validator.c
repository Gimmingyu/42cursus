/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:28:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/12 17:36:49 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_integer(char *str)
{
	size_t	idx;
	size_t	len;

	if (!str)
		return (ERROR);
	idx = 0;
	len = ft_strlen(str);
	if ((str[0] != '-' && str[0] != '+') && (str[0] < '0' || str[0] > '9'))
		return (ERROR);
	if (str[0] == '-' || str[0] == '+')
		idx++;
	while (str[idx] && idx < len)
	{
		if (str[idx] && (str[idx] < '0' || str[idx] > '9'))
			return (ERROR);
		idx++;
	}
	return (OK);
}

int	check_duplicate(char **str)
{
	size_t	idx;
	size_t	sub_idx;

	if (!str)
		return (ERROR);
	idx = 0;
	while (str[++idx])
	{
		sub_idx = -1;
		while (++sub_idx < idx)
			if (str[sub_idx] == str[idx])
				return (ERROR);
	}
	return (OK);
}

void	validator(int ac, char **av, \
					t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	char	**temp;
	size_t	idx;
	size_t	temp_idx;
	int		sign;

	if (ac == 1)
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
			printf("temp[%zu] = %s\n", temp_idx, temp[temp_idx]);
			if (is_integer(temp[temp_idx]) == ERROR || \
					check_duplicate(temp) == ERROR)
				sign = response_error() * delete_all_stack(a_stack, b_stack);
			push_bottom(a_stack, a_to_longlong(temp[temp_idx]), 0);
		}
		ft_malloc_error(temp);
	}
}
