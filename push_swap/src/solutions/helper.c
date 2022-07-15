/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 15:22:50 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	select_pivot(t_linked_stack *stack, long *pivot_a_ptr, long *pivot_b_ptr)
{
	long			*array;
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack || is_linked_stack_empty(stack) == TRUE)
		response_error();
	array = malloc(sizeof(long) * (stack->element_count + 1));
	if (!array)
		response_error();
	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count)
	{
		array[idx++] = node->value;
		node = node->next;
	}
	bubble_sort(&array, idx);
	*pivot_b_ptr = array[idx / 3];
	*pivot_a_ptr = array[(idx / 3) * 2];
	free(array);
	return (TRUE);
}

void	bubble_sort(long **array_ptr, ssize_t size)
{
	ssize_t			i;
	ssize_t			j;
	int				temp;

	if (!*array_ptr)
		response_error();
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if ((*array_ptr)[j] > (*array_ptr)[j + 1])
			{
				temp = (*array_ptr)[j];
				(*array_ptr)[j] = (*array_ptr)[j + 1];
				(*array_ptr)[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
