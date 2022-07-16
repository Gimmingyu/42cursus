/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:28:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/16 16:08:07 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (TRUE);
}

static int	check_duplicate(char **str)
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
	return (TRUE);
}

void	check_duplicate_elem(t_linked_stack *stack)
{
	ssize_t			i;
	ssize_t			j;
	long			k;
	t_stack_node	*node;

	if (!stack || is_linked_stack_empty(stack))
		response_error();
	i = 0;
	while (i++ < stack->element_count)
	{
		node = stack->top_node.next;
		k = node->value;
		j = 0;
		while (j++ < stack->element_count - 1)
		{
			node = node->next;
			if (node->value == k)
				response_error();
		}
	}
}

void	validator(int ac, char **av, \
					t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	char	**temp;
	ssize_t	idx;
	ssize_t	temp_idx;

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
			push_bottom(a_stack, ft_atol(temp[temp_idx]));
		}
		ft_malloc_error(temp);
	}
}
