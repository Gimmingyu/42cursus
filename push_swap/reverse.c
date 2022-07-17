/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/16 23:48:33 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_reverse_rotate(t_linked_stack *stack, t_command command)
{
	t_stack_node	*bottom_node;

	if (!stack)
		response_error();
	if (stack->element_count > 1)
	{
		bottom_node = pop_on_bottom(stack);
		if (!bottom_node)
			response_error();
		push_top(stack, bottom_node->value);
		free(bottom_node);
		if (command == RRA)
			write(1, "rra\n", 4);
		else if (command == RRB)
			write(1, "rrb\n", 4);
		return (TRUE);
	}
	return (FALSE);
}

int	both_reverse_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack)
		response_error();
	single_reverse_rotate(a_stack, RRR);
	single_reverse_rotate(b_stack, RRR);
	write(1, "rrr\n", 4);
	return (TRUE);
}
