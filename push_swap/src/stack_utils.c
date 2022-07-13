/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:21:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 19:44:25 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_linked_stack_empty(t_linked_stack *stack)
{
	if (stack->element_count == 0)
		return (OK);
	return (FALSE);
}

int	copy_stack(t_linked_stack *stack, t_linked_stack **stack_ptr)
{
	ssize_t			idx;
	t_stack_node	*node;
	t_stack_node	*temp;

	if (!stack || is_linked_stack_empty(stack))
		return (ERROR);
	idx = 0;
	node = stack->top_node.next;
	(*stack_ptr) = malloc(sizeof(t_linked_stack));
	if (!*stack_ptr)
		return (ERROR);
	(*stack_ptr)->element_count = 0;
	(*stack_ptr)->top_node.next = NULL;
	(*stack_ptr)->top_node.prev = NULL;
	while (idx < stack->element_count)
	{
		push_bottom(*stack_ptr, node->value, node->target_idx);
		node = node->next;
		idx++;
	}
	return (OK);
}

t_stack_node	*copy_node(t_stack_node *node)
{
	t_stack_node	*new_node;

	if (!node)
		return (NULL);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->target_idx = node->target_idx;
	new_node->value = node->value;
	return (new_node);
}

int	is_sorted(t_linked_stack *stack)
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
		if (is_greater(node->value, node->next->value) == OK)
			return (FALSE);
		node = node->next;
	}
	return (OK);
}
