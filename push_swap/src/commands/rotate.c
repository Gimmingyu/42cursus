/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/11 23:58:05 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_rotate(t_linked_stack *stack)
{
	t_stack_node	*top_node;
	t_stack_node	*bottom_node;
	t_type			result;

	if (!stack || is_linked_stack_empty(stack))
		return (ERROR);
	if (stack->element_count == 1)
		return (OK);
	top_node = pop_on_top(stack);
	if (!top_node)
		return (ERROR);
	result = OK;
	if (!push_bottom(stack, top_node->value))
		result = ERROR;
	free(top_node);
	return (result);
}

int	both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack || \
		is_linked_stack_empty(a_stack) || is_linked_stack_empty(b_stack))
		return (FALSE);
	if (single_rotate(a_stack))
		return (FALSE);
	if (single_rotate(b_stack))
		return (FALSE);
	return (OK);
}
