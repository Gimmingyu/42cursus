/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 16:00:00 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	select_pivot(t_linked_stack *stack, int *pivot_a_ptr, int *pivot_b_ptr)
{
	int				*array;
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack || is_linked_stack_empty(stack) == OK)
		response_error();
	array = malloc(sizeof(int) * stack->element_count);
	if (!array)
		response_error();
	idx = -1;
	node = stack->top_node.next;
	while (++idx < stack->element_count)
	{
		array[idx] = node->value;
		node = node->next;
	}
	bubble_sort(&array, idx);
	*pivot_b_ptr = array[idx / 3];
	*pivot_a_ptr = array[(idx / 3) * 2];
	free(array);
	return (OK);
}

void	bubble_sort(int **array_ptr, ssize_t size)
{
	ssize_t			idx;
	ssize_t			next_idx;
	int				temp;

	if (!*array_ptr)
		response_error();
	idx = 0;
	while ((*array_ptr)[idx] && idx < size)
	{
		next_idx = 0;
		while (next_idx < size - 1)
		{
			if ((*array_ptr)[next_idx] > (*array_ptr)[next_idx + 1])
			{
				temp = (*array_ptr)[next_idx];
				(*array_ptr)[next_idx] = (*array_ptr)[next_idx + 1];
				(*array_ptr)[next_idx + 1] = temp;
			}
			next_idx++;
		}
	}
}
