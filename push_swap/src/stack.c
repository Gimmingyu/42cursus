/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:07:17 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/10 23:07:00 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	delete_stack(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*next_node;

	idx = 0;
	node = a_stack->top_node.next;
	while (idx++ < a_stack->element_count)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	idx = 0;
	node = b_stack->top_node.next;
	while (idx++ < b_stack->element_count)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(a_stack);
	free(b_stack);
	return (0);
}

int	is_linked_stack_empty(t_linked_stack *stack)
{
	if (stack->element_count == 0)
		return (1);
	return (0);
}

void	create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr)
{
	*a_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*a_ptr)
		response_error();
	*b_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*b_ptr)
	{
		free(a_ptr);
		response_error();
	}
	(*a_ptr)->element_count = 0;
	(*b_ptr)->element_count = 0;
	(*a_ptr)->top_node.prev = NULL;
	(*a_ptr)->top_node.next = NULL;
	(*b_ptr)->top_node.prev = NULL;
	(*b_ptr)->top_node.next = NULL;
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	return (new_node);
}

int	copy_stack(t_linked_stack *stack, t_linked_stack **copy_stack_ptr)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*temp;

	if (!stack || is_linked_stack_empty(stack))
		return (ERROR);
	idx = 0;
	node = stack->top_node.next;
	(*copy_stack_ptr) = malloc(sizeof(t_linked_stack));
	if (!*copy_stack_ptr)
		return (ERROR);
	(*copy_stack_ptr)->element_count = 0;
	(*copy_stack_ptr)->top_node.next = NULL;
	(*copy_stack_ptr)->top_node.prev = NULL;
	while (idx < stack->element_count)
	{
		push_bottom(*copy_stack_ptr, node->value);
		node = node->next;
		idx++;
	}
	return (OK);
}
