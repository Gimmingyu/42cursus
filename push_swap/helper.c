/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:57:23 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_pivot(t_linked_stack *stack, ssize_t range, \
					long *pivot_a_ptr, long *pivot_b_ptr)
{
	long			*array;
	ssize_t			idx;
	t_stack_node	*node;

	if (!stack || is_linked_stack_empty(stack) == TRUE)
		response_error();
	array = malloc(sizeof(long) * range);
	if (!array)
		response_error();
	idx = 0;
	node = stack->top_node.next;
	while (idx < range)
	{
		array[idx++] = node->value;
		node = node->next;
	}
	bubble_sort(&array, range);
	*pivot_b_ptr = array[range / 3];
	*pivot_a_ptr = array[range / 3 * 2];
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
		j = i;
		while (j < size)
		{
			if ((*array_ptr)[i] > (*array_ptr)[j])
			{
				temp = (*array_ptr)[i];
				(*array_ptr)[i] = (*array_ptr)[j];
				(*array_ptr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}
