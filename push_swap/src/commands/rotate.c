/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 16:49:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_rotate(t_linked_stack *stack, t_command command)
{
	t_stack_node	*top_node;

	if (!stack)
		response_error();
	if (is_linked_stack_empty(stack) || stack->element_count == 1 \
			|| command == NONE)
		return (OK);
	top_node = pop_on_top(stack);
	if (!top_node)
		response_error();
	push_bottom(stack, top_node->value, top_node->target_idx);
	free(top_node);
	if (command == RA)
		write(1, "ra\n", 3);
	else if (command == RB)
		write(1, "rb\n", 3);
	return (OK);
}

int	both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack)
		response_error();
	single_rotate(a_stack, RR);
	single_rotate(b_stack, RR);
	write(1, "rr\n", 3);
	return (OK);
}
