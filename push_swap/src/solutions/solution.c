/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/10 23:40:31 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pivot_a보다 크면 ra, pivot a보다는 작고, pivot b보다는 크면 pb, pivot b보다 작으면 pb rb
int	quick_sort(t_linked_stack *stack, t_info *info)
{
	t_stack_node	*node;
	size_t			idx;

	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count - 1)
	{
		idx++;
	}
	return (OK);
}

int	solution(t_linked_stack *a_stack, t_linked_stack *b_stack, t_linked_stack *copy_stack)
{
	int		pivot_a;
	int		pivot_b;
	t_info	*info;

	if (!a_stack || !b_stack || !copy_stack || \
	is_linked_stack_empty(a_stack) || is_linked_stack_empty(copy_stack))
		return (ERROR);
	bubble_sort(copy_stack);
	if (select_pivot(copy_stack, &pivot_a, &pivot_b) == ERROR)
		return (ERROR);
	info = create_info(pivot_a, pivot_b);
	if (!info)
		return (ERROR);
	printf("pivot_a = %d\n", pivot_a);
	printf("pivot_b = %d\n", pivot_b);
	return (quick_sort(a_stack, info));
}
