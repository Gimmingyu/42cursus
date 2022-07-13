/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:43 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 19:14:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	step_one(t_linked_stack *a_stack, t_linked_stack *b_stack, t_info *info)
{
	t_stack_node	*a_top;

	while (find_min_value(a_stack, info->pivot_a))
	{
		a_top = a_stack->top_node.next;
		if (info->pivot_b <= a_top->value && a_top->value < info->pivot_a)
		{
			push(b_stack, a_stack, PB);
			if (is_reverse_sorted(b_stack) == FALSE)
				single_rotate(b_stack, RB);
		}
		else if (a_top->value < info->pivot_b)
			push(b_stack, a_stack, PB);
		else
			single_rotate(a_stack, RA);
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
	idx = -1;
	node = stack->top_node.next;
	while (++idx < stack->element_count - 1)
	{
		if (is_greater(node->next->value, node->value) == OK)
			return (FALSE);
		node = node->next;
	}
	return (OK);
}
