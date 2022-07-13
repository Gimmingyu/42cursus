/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:44:12 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 11:44:23 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
