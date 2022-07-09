/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:03:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/09 13:38:37 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	push_bottom(t_linked_stack *stack, int value)
{
	t_stack_node	*node;

	if (!stack)
		return (FALSE);
	node = create_node(value);
	if (!node)
		return (ERROR);
	if (is_linked_stack_empty(stack) == OK)
	{
		stack->top_node.prev = node;
		stack->top_node.next = node;
	}
	else
	{
		stack->top_node.prev->next = node;
		stack->top_node.next->prev = node;
	}
	node->prev = stack->top_node.prev;
	node->next = stack->top_node.next;
	stack->top_node.prev = node;
	stack->element_count++;
	return (OK);
}

int	push_top(t_linked_stack *stack, t_stack_node push_node)
{
	t_stack_node	*node;

	if (!stack)
		return (FALSE);
	node = create_node(push_node.value);
	if (!node)
		return (ERROR);
	if (is_linked_stack_empty(stack))
	{
		stack->top_node.next = node;
		stack->top_node.prev = node;
	}
	else
	{
		stack->top_node.next->prev = node;
		stack->top_node.prev->next = node;
	}
	node->next = stack->top_node.next;
	node->prev = stack->top_node.prev;
	stack->element_count++;
	return (OK);
}

t_stack_node	*pop_on_top(t_linked_stack *stack)
{
	t_stack_node	*top_node;

	if (!stack || is_linked_stack_empty(stack))
		return (NULL);
	top_node = stack->top_node.next;
	stack->top_node.next = top_node->next;
	top_node->next->prev = &stack->top_node;
	stack->element_count--;
	return (top_node);
}

int	push(t_linked_stack *push_stack, t_linked_stack *pop_stack)
{
	t_stack_node	*pop_node;
	t_type			result;

	if (!push_stack || !pop_stack || is_linked_stack_empty(pop_stack))
		return (FALSE);
	pop_node = pop_on_top(pop_stack);
	if (!pop_node)
		return (FALSE);
	result = OK;
	if (push_top(push_stack, *pop_node) == ERROR)
		result = ERROR;
	free(pop_node);
	return (result);
}
