/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:43 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/12 22:41:58 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	step_one(t_linked_stack *a_stack, t_linked_stack *b_stack, t_info *info)
{
	t_stack_node	*a_top;
	int				temp;

	temp = 1;
	while (a_stack->element_count > 3 && find_min_value(a_stack, info->pivot_a))
	{
		a_top = a_stack->top_node.next;
		if (info->pivot_b <= a_top->value && a_top->value < info->pivot_a)
			temp *= push(b_stack, a_stack, PB) * single_rotate(b_stack, RB);
		else if (a_top->value < info->pivot_b)
			temp *= push(b_stack, a_stack, PB);
		else
			temp *= single_rotate(a_stack, RA);
	}
	if (temp != OK)
		return (ERROR);
	return (OK);
}

int	step_two(t_linked_stack *a_stack, t_linked_stack *b_stack, t_info *info)
{
	t_stack_node	*a_top;
	size_t			idx;

	if (is_sorted(a_stack))
		return (OK);
	while (a_stack->element_count > 3)
		push(b_stack, a_stack, PB);
	if (a_stack->element_count == 2)
		return (opt_two(a_stack));
	if (a_stack->element_count == 3)
		return (opt_three(a_stack));
	return (ERROR);
}

int	step_three(t_linked_stack *a_stack, t_linked_stack *b_stack, t_info *info)
{
	int	ra_count;

	if (!a_stack || !b_stack || !info || \
			is_linked_stack_empty(b_stack) || is_linked_stack_empty(a_stack))
		return (ERROR);
	ra_count = 0;
	while (is_linked_stack_empty(b_stack) == FALSE)
	{
		while (a_stack->top_node.next->target_idx < \
				b_stack->top_node.next->target_idx)
		{
			if (single_rotate(a_stack, RA) == ERROR)
				return (ERROR);
			ra_count++;
		}
		push(a_stack, b_stack, PA);
		while (ra_count--)
			if (single_reverse_rotate(a_stack, RA) == ERROR)
				return (ERROR);
		ra_count = 0;
	}
	return (OK);
}

int	rotate_or_reverse(t_linked_stack *a_stack, int count)
{
	size_t	idx;

	idx = get_max_value_index(a_stack);
	return (OK);
}
