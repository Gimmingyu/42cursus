/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/11 13:56:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_reverse_rotate(t_linked_stack *stack)
{
	t_stack_node	*bottom_node;
	t_type			result;

	if (!stack || is_linked_stack_empty(stack))
		return (FALSE);
	bottom_node = pop_on_bottom(stack);
	if (!bottom_node)
		return (FALSE);
	result = OK;
	if (!push_top(stack, bottom_node->value))
		result = FALSE;
	free(bottom_node);
	return (result);
}

int	both_reverse_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack || \
		is_linked_stack_empty(a_stack) || is_linked_stack_empty(b_stack))
		return (FALSE);
	if (single_reverse_rotate(a_stack) == FALSE)
		return (FALSE);
	if (single_reverse_rotate(b_stack) == FALSE)
		return (FALSE);
	return (OK);
}
