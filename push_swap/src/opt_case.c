/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:43:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:47:30 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	opt3_case1(t_linked_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	if (!stack)
		response_error();
	top = stack->top_node.next->value;
	mid = stack->top_node.next->next->value;
	bottom = stack->top_node.next->next->next->value;
	// 0 2 1 => 0 1 2
	if (top < bottom && bottom < mid)
	{
		single_reverse_rotate(stack, RRA);
		single_rotate(stack, RA);
		single_swap(stack, SA);
	}
	else if (mid < bottom && bottom < top)
	{
		single_swap(stack, SA);
		single_rotate(stack, RA);
		single_swap(stack, SA);
		single_reverse_rotate(stack, RRA);
	}
	else if (mid < top && top < bottom)
		single_swap(stack, SA);
	return (TRUE);
}

int	opt3_case2(t_linked_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	if (!stack)
		response_error();
	top = stack->top_node.next->value;
	mid = stack->top_node.next->next->value;
	bottom = stack->top_node.next->next->next->value;
	if (bottom < mid && mid < top)
	{
		single_swap(stack, SA);
		single_rotate(stack, RA);
		single_swap(stack, SA);
		single_reverse_rotate(stack, RRA);
		single_swap(stack, SA);
	}
	else
	{
		single_rotate(stack, RA);
		single_swap(stack, SA);
		single_reverse_rotate(stack, RRA);
		single_swap(stack, SA);
	}
	return (TRUE);
}
