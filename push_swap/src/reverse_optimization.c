/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_optimization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:54:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 15:23:23 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reversed_opt_three(t_linked_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;
	int	temp;

	top = stack->top_node.next->value;
	mid = stack->top_node.next->next->value;
	bottom = stack->top_node.prev->value;
	if (top < bottom && bottom < mid)
		temp = single_rotate(stack, RB);
	else if (mid < bottom && bottom < top)
		temp = single_swap(stack, SB) * single_rotate(stack, RA);
	else if (mid < top && top < bottom)
		temp = single_reverse_rotate(stack, RRB);
	else if (top < mid && mid < bottom)
		temp = single_swap(stack, SB) * single_reverse_rotate(stack, RRB);
	else
		temp = single_swap(stack, SB);
	return (temp);
}

int	reversed_opt_two(t_linked_stack *stack)
{
	if (!stack || stack->element_count != 2)
		response_error();
	if (stack->top_node.next->value > stack->top_node.prev->value)
		return (TRUE);
	return (single_swap(stack, SB));
}

int	reversed_opt_five(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_stack_node	*node;
	int				min_value;

	if (!a_stack || !b_stack || b_stack->element_count != 5)
		response_error();
	min_value = find_max_value(b_stack);
	while (b_stack->element_count > 3)
	{
		node = a_stack->top_node.next;
		if (node->value == min_value)
		{
			push(a_stack, b_stack, PA);
			min_value = find_max_value(b_stack);
		}
		single_rotate(b_stack, RB);
	}
	if (b_stack->element_count == 3)
		reversed_opt_three(b_stack);
	node = a_stack->top_node.next;
	if (node->value > node->next->value)
		single_swap(b_stack, SB);
	push(b_stack, a_stack, PB);
	push(b_stack, a_stack, PB);
	return (TRUE);
}

int	b_opt(t_linked_stack *as, t_linked_stack *bs)
{
	if (!as || !bs)
		response_error();
	else if (bs->element_count == 1)
		return (push(as, bs, PA));
	else if (is_reverse_sorted(bs))
		return (TRUE);
	else if (bs->element_count == 2)
		return (reversed_opt_two(bs));
	else if (bs->element_count == 3)
		return (reversed_opt_three(bs));
	else if (bs->element_count == 5)
		return (reversed_opt_five(bs, as));
	return (FALSE);
}
