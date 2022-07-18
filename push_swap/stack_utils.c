/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:21:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:38:43 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_linked_stack_empty(t_linked_stack *stack)
{
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
	while (idx++ < range)
	{
		if (node->value > node->next->value)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

int	find_min_value(t_linked_stack *stack)
{
	t_stack_node	*node;
	ssize_t			idx;
	long			min_value;

	if (!stack)
		response_error();
	idx = 0;
	min_value = 2147483648;
	node = stack->top_node.next;
	while (idx++ < stack->element_count)
	{
		if (node->value < min_value)
			min_value = node->value;
		node = node->next;
	}
	return (min_value);
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
