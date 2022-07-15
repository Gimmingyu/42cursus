/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_optimization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:54:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:59:33 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reversed_opt_actual_three(t_linked_stack *as, t_linked_stack *bs)
{
	int	top;
	int	mid;
	int	bottom;

	if (!bs || bs->element_count != 3)
		response_error();
	top = bs->top_node.next->value;
	mid = bs->top_node.next->next->value;
	bottom = bs->top_node.prev->value;
	if (top < bottom && bottom < mid)
	{
		single_rotate(bs, RB);
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (top < mid && mid < bottom)
	{
		single_reverse_rotate(bs, RRB);
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (mid < bottom && bottom < top)
	{
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (mid < top && top < bottom)
	{
		
	}
		single_reverse_rotate(bs, RRB);
	else if (bottom < top && bottom < mid)
		single_swap(bs, SB);
	return (TRUE);
}

int	reversed_opt_three(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!bs)
		response_error();
	tmb[0] = bs->top_node.next->value;
	tmb[1] = bs->top_node.next->next->value;
	tmb[2] = bs->top_node.prev->value;
	reverse_opt3_case1(bs, tmb);
	reverse_opt3_case2(bs, tmb);
	return (TRUE);
}

int	reversed_opt_two(t_linked_stack *as, t_linked_stack *bs)
{
	if (!bs)
		response_error();
	if (bs->top_node.next->value < bs->top_node.prev->value)
		single_swap(bs, SB);
	push(as, bs, PA);
	push(as, bs, PA);
	return (TRUE);
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
		reversed_opt_actual_three(a_stack, b_stack);
	node = a_stack->top_node.next;
	if (node->value > node->next->value)
		single_swap(b_stack, SB);
	return (TRUE);
}

int	b_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k)
{
	if (!as || !bs || k < 0)
		response_error();
	else if (bs->element_count > 3 && k == 3)
		return (reversed_opt_three(as, bs));
	else if (bs->element_count == 3 && k == 3)
		return (reversed_opt_actual_three(as, bs));
	else if (k == 3 && bs->element_count == 2)
		return (reversed_opt_two(as, bs));
	else if (k == 3)
		return (push(as, bs, PA));
	else if (k == 2 && bs->element_count >= 2)
		return (reversed_opt_two(as, bs));
	else if (k == 2 || k == 1)
		return (push(as, bs, PA));
	return (TRUE);
}
