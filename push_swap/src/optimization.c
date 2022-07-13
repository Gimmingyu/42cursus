/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 13:29:49 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	opt_three(t_linked_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;
	int	temp;

	top = stack->top_node.next->value;
	mid = stack->top_node.next->next->value;
	bottom = stack->top_node.prev->value;
	if (top < bottom && bottom < mid)
		temp = single_swap(stack, SA) * single_rotate(stack, RA);
	else if (mid < bottom && bottom < top)
		temp = single_rotate(stack, RA);
	else if (mid < top && top < bottom)
		temp = single_swap(stack, SA);
	else if (bottom < mid && mid < top)
		temp = single_swap(stack, SA) * single_reverse_rotate(stack, RRA);
	else
		temp = single_reverse_rotate(stack, RRA);
	return (temp);
}

int	opt_two(t_linked_stack *stack)
{
	return (single_swap(stack, SA));
}
