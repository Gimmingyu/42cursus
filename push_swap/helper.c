/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:57:23 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(long **array_ptr, ssize_t size)
{
	ssize_t			i;
	ssize_t			j;
	int				temp;

	if (!*array_ptr)
		response_error();
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if ((*array_ptr)[i] > (*array_ptr)[j])
			{
				temp = (*array_ptr)[i];
				(*array_ptr)[i] = (*array_ptr)[j];
				(*array_ptr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	select_pivot(t_linked_stack *stack, ssize_t range, \
					long *pivot_a_ptr, long *pivot_b_ptr)
{
	long			*array;
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack || is_linked_stack_empty(stack) == TRUE)
		response_error();
	array = malloc(sizeof(long) * range);
	if (!array)
		response_error();
	idx = 0;
	node = stack->top_node.next;
	while (idx < range)
	{
		array[idx++] = node->value;
		node = node->next;
	}
	bubble_sort(&array, range);
	*pivot_b_ptr = array[range / 3];
	*pivot_a_ptr = array[range / 3 * 2];
	free(array);
	return (TRUE);
}


int	is_linked_stack_empty(t_linked_stack *stack)
{
	if (!stack)
		response_error();
	if (stack->element_count == 0)
		return (TRUE);
	return (FALSE);
}

int	is_sorted(t_linked_stack *stack, ssize_t range)
{
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack)
		response_error();
	if (stack->element_count == 1)
		return (TRUE);
	idx = 0;
	node = stack->top_node.next;
	while (idx++ < range - 1)
	{
		if (node->value > node->next->value)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void	find_minimum_two(t_linked_stack *as, long *min_ptr, \
							long *second_min_ptr)
{
	t_stack_node	*node;
	ssize_t			idx;
	long			min;
	long			second_min;

	idx = 0;
	node = as->top_node.next;
	min = 2147483648;
	second_min = 2147483648;
	while (idx++ < as->element_count)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	idx = 0;
	while (idx++ < as->element_count)
	{
		if (node->value > min && node->value < second_min)
			second_min = node->value;
		node = node->next;
	}
	*min_ptr = min;
	*second_min_ptr = second_min;
}
