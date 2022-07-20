/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:28:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:24:18 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && 13 >= c))
		return (1);
	return (0);
}

static long a_to_long(const char *str)
{
	long	nbr;
	int			sign;
	ssize_t		i;

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
		if (nbr > 2147483647 && sign == 1)
			response_error();
		else if (nbr > 2147483648 && sign == -1)
			response_error();
		i++;
	}
	return (sign * nbr);
}

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

static void	check_duplicate_elem(t_linked_stack *stack)
{
	long			*array;
	t_stack_node	*node;
	ssize_t			idx;
	ssize_t			idx_temp;

	if (!stack || is_linked_stack_empty(stack) == TRUE)
		response_error();
	array = malloc(sizeof(long) * stack->element_count);
	if (!array)
		response_error();
	node = stack->top_node.next;
	idx = 0;
	while (idx < stack->element_count)
	{
		array[idx++] = node->value;
		node = node->next;
	}
	idx = -1;
	while (++idx < stack->element_count)
	{
		idx_temp = -1;
		while (++idx_temp < stack->element_count)
			if (array[idx_temp] == array[idx] && idx != idx_temp)
				response_error();
	}
	free(array);
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
			if (is_integer(temp[temp_idx]) == ERROR)
				response_error();
			push_bottom(a_stack, a_to_long(temp[temp_idx]));
		}
		ft_malloc_error(temp);
	}
	check_duplicate_elem(a_stack);
}
