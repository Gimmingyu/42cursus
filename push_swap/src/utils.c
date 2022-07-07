/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:27:25 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/07 19:35:47 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_linked_stack_empty(t_linked_stack *stack)
{
	if (stack->element_count == 0)
		return (1);
	return (0);
}

void	delete_stack(t_linked_stack *stack)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*next_node;

	if (!stack)
		return ;
	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count)
	{
		next_node = node->next;
		free(node);
		node->next = NULL;
		node->prev = NULL;
		node = next_node;
		idx++;
	}
	next_node = NULL;
	node = NULL;
}

void	display_stack(t_linked_stack *stack)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*next_node;

	if (!stack)
		return ;
	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count)
	{
		next_node = node->next;
		printf("%zu번째 value는 %d 입니다.\n", idx, node->value);
		node = next_node;
		idx++;
	}
}
