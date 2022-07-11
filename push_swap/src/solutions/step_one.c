/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:43 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/11 23:54:06 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	step_one(t_linked_stack *a_stack, t_linked_stack *b_stack, \
				t_info *info)
{
	t_stack_node	*a_top;
	size_t			idx;
	int				temp;

	idx = 0;
	printf("pivot_a = %d, pivot_b = %d\n", info->pivot_a, info->pivot_b);
	while (a_stack->element_count > 3 && find_min_value(a_stack, info->pivot_b))
	{
		a_top = a_stack->top_node.next;
		if (info->pivot_b <= a_top->value && a_top->value < info->pivot_a)
			temp *= push(b_stack, a_stack) * single_rotate(b_stack);
		else if (a_top->value < info->pivot_b)
			temp *= push(b_stack, a_stack);
		else
			temp *= single_rotate(a_stack);
		display_stack(a_stack);
	}
	if (temp != OK)
		return (ERROR);
	return (OK);
}