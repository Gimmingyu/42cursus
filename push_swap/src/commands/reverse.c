/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/12 16:10:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_reverse_rotate(t_linked_stack *stack)
{
	t_stack_node	*bottom_node;
	t_type			result;

	if (!stack || is_linked_stack_empty(stack))
		return (ERROR);
	bottom_node = pop_on_bottom(stack);
	if (!bottom_node)
		return (ERROR);
	result = OK;
	if (!push_top(stack, bottom_node->value, bottom_node->target_idx))
		result = ERROR;
	free(bottom_node);
	return (result);
}

int	both_reverse_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack || \
		is_linked_stack_empty(a_stack) || is_linked_stack_empty(b_stack))
		return (ERROR);
	if (single_reverse_rotate(a_stack) == ERROR)
		return (ERROR);
	if (single_reverse_rotate(b_stack) == ERROR)
		return (ERROR);
	return (OK);
}
