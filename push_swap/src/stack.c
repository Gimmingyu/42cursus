/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:07:17 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 11:53:30 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	delete_all_stack(t_linked_stack *a_stack, t_linked_stack *b_stack)
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

void	create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr)
{
	*a_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*a_ptr)
		response_error();
	*b_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*b_ptr)
		response_error();
	(*a_ptr)->element_count = 0;
	(*b_ptr)->element_count = 0;
	(*a_ptr)->top_node.prev = NULL;
	(*a_ptr)->top_node.next = NULL;
	(*b_ptr)->top_node.prev = NULL;
	(*b_ptr)->top_node.next = NULL;
}

t_stack_node	*create_node(int value, size_t idx)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->target_idx = idx;
	return (new_node);
}

int	delete_single_stack(t_linked_stack *stack)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*next_node;

	idx = 0;
	node = stack->top_node.next;
	while (idx++ < stack->element_count)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(stack);
	return (ERROR);
}
