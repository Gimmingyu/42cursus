/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/10 23:39:36 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_sum_of_stack(t_linked_stack *stack)
{
	size_t			idx;
	int				ret;
	t_stack_node	*node;

	ret = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count - 1)
	{
		ret += node->value;
		node = node->next;
	}
	return (ret);
}

int	select_pivot(t_linked_stack *stack, int *pivot_a_ptr, int *pivot_b_ptr)
{
	int				*array;
	size_t			idx;
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
	*pivot_a_ptr = array[idx / 3];
	*pivot_b_ptr = array[(idx / 3) * 2];
	free(array);
	return (OK);
}

void	bubble_sort(t_linked_stack *stack)
{
	size_t			idx;
	size_t			idx_temp;
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
