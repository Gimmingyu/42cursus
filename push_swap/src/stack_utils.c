/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:21:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 16:58:20 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_linked_stack_empty(t_linked_stack *stack)
{
	if (stack->element_count == 0)
		return (OK);
	return (FALSE);
}

int	is_sorted(t_linked_stack *stack)
{
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack)
		response_error();
	if (stack->element_count == 1)
		return (OK);
	idx = 0;
	node = stack->top_node.next;
	while (idx++ < stack->element_count - 1)
	{
		if (is_greater(node->value, node->next->value) == OK)
			return (FALSE);
		node = node->next;
	}
	return (OK);
}

int	is_reverse_sorted(t_linked_stack *stack)
{
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack)
		response_error();
	if (stack->element_count == 1)
		return (OK);
	idx = 0;
	node = stack->top_node.next;
	while (idx++ < stack->element_count)
	{
		if (is_greater(node->value, node->next->value) == FALSE)
			return (FALSE);
		node = node->next;
	}
	return (OK);
}

int	find_min_value(t_linked_stack *stack)
{
	t_stack_node	*node;
	ssize_t			idx;
	int				min_value;

	if (!stack)
		response_error();
	idx = 0;
	min_value = 2147483647;
	node = stack->top_node.next;
	while (idx++ < stack->element_count)
	{
		if (node->value < min_value)
			min_value = node->value;
		node = node->next;
	}
	return (min_value);
}
