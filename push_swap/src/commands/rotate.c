/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/12 22:34:57 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_rotate(t_linked_stack *stack, t_command command)
{
	t_stack_node	*top_node;
	t_stack_node	*bottom_node;
	int				result;

	if (!stack || is_linked_stack_empty(stack))
		return (ERROR);
	if (stack->element_count == 1)
		return (OK);
	top_node = pop_on_top(stack);
	if (!top_node)
		return (ERROR);
	result = OK;
	if (!push_bottom(stack, top_node->value, top_node->target_idx))
		result = ERROR;
	free(top_node);
	if (command == RA)
		write(1, "ra ", 3);
	else if (command == RB)
		write(1, "rb ", 3);
	return (result);
}

int	both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack || \
		is_linked_stack_empty(a_stack) || is_linked_stack_empty(b_stack))
		return (FALSE);
	if (single_rotate(a_stack, RR) == ERROR)
		return (FALSE);
	if (single_rotate(b_stack, RR) == ERROR)
		return (FALSE);
	write(1, "rr ", 3);
	return (OK);
}
