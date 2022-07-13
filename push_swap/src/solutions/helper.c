/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 01:04:34 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	select_pivot(t_linked_stack *stack, int *pivot_a_ptr, int *pivot_b_ptr)
{
	int				*array;
	ssize_t			idx;
	t_stack_node	*node;

	array = malloc(sizeof(int) * stack->element_count);
	if (!array)
		return (ERROR);
	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count - 1)
	{
		array[idx++] = node->value;
		node = node->next;
	}
	*pivot_b_ptr = array[idx / 3];
	*pivot_a_ptr = array[(idx / 3) * 2];
	free(array);
	return (OK);
}

void	bubble_sort(t_linked_stack *stack)
{
	ssize_t			idx;
	ssize_t			idx_temp;
	t_stack_node	*temp;
	int				i;

	idx = -1;
	while (++idx < stack->element_count - 1)
	{
		idx_temp = -1;
		temp = stack->top_node.next;
		while (++idx_temp < stack->element_count - 1)
		{
			if (temp->value > temp->next->value)
			{
				i = temp->value;
				temp->value = temp->next->value;
				temp->next->value = i;
			}
			temp = temp->next;
		}
	}
}

int	set_index(t_linked_stack *stack, t_linked_stack *copied)
{
	ssize_t			i;
	ssize_t			j;
	ssize_t			idx;
	t_stack_node	*node;
	t_stack_node	*copied_node;

	idx = 0;
	copied_node = copied->top_node.next;
	node = stack->top_node.next;
	while (idx < stack->element_count)
	{
		if (node->value == copied_node->value)
		{
			copied_node = copied_node->next;
			node->target_idx = idx;
			idx++;
		}
		node = node->next;
	}
	return (OK);
}

int	find_min_value(t_linked_stack *stack, int key)
{
	t_stack_node	*head;
	ssize_t			idx;

	head = stack->top_node.next;
	idx = 0;
	while (idx < stack->element_count - 1)
	{
		if (head->value < key)
			return (OK);
		head = head->next;
		idx++;
	}
	return (FALSE);
}

int	check_top(t_linked_stack *stack, ssize_t max_index)
{
	t_stack_node	*node;
	ssize_t			target_idx;
	ssize_t			len;

	if (!stack || is_linked_stack_empty(stack))
		response_error();
	target_idx = 2147483647;
	len = -1;
	node = stack->top_node.next;
	while (++len <= stack->element_count)
	{
		if (node->target_idx > max_index && node->target_idx <= target_idx)
			target_idx = len;
		node = node->next;
	}
	if (target_idx == 0)
		return (OK);
	return (FALSE);
}
