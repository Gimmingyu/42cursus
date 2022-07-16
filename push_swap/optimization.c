/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:54:24 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt_actual3(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!as || as->element_count != 3)
		response_error();
	tmb[0] = as->top_node.next->value;
	tmb[1] = as->top_node.next->next->value;
	tmb[2] = as->top_node.prev->value;
	if (is_sorted(as, as->element_count) == TRUE)
		return (TRUE);
	else
	{
		opt_actual3_case1(as, bs, tmb);
		opt_actual3_case2(as, bs, tmb);
	}
	return (TRUE);
}

int	opt5(t_linked_stack *as, t_linked_stack *bs)
{
	long			min_value;
	t_stack_node	*node;

	if (!as || !bs)
		response_error();
	if (as->element_count != 5)
		return (FALSE);
	if (is_sorted(as, as->element_count) == TRUE)
		return (TRUE);
	min_value = find_min_value(as);
	while (as->element_count > 3)
	{
		node = as->top_node.next;
		if (node->value == min_value)
		{
			push(bs, as, PB);
			min_value = find_min_value(as);
		}
		else
			single_rotate(as, RA);
	}
	if (as->element_count == 3)
		opt_actual3(as, bs);
	push(as, bs, PA);
	push(as, bs, PA);
	return (TRUE);
}

int	opt3(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!as || !bs || as->element_count < 3)
		response_error();
	tmb[0] = as->top_node.next->value;
	tmb[1] = as->top_node.next->next->value;
	tmb[2] = as->top_node.next->next->next->value;
	if (is_sorted(as, 3) == TRUE)
		return (TRUE);
	else
	{
		opt3_case1(as, bs, tmb);
		opt3_case2(as, bs, tmb);
	}
	return (TRUE);
}

int	opt2(t_linked_stack *as, t_linked_stack *bs)
{
	if (!as || !bs)
		response_error();
	if (as->top_node.next->value > as->top_node.next->next->value)
		single_swap(as, SA);
	return (TRUE);
}

int	a_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k)
{
	if (!as || !bs)
		response_error();
	else if (k == 3 && as->element_count == 3)
		return (opt_actual3(as, bs));
	else if (k == 3 && as->element_count > 3)
		return (opt3(as, bs));
	else if ((k == 3 && as->element_count < 2) || (0 <= k && k <= 2))
		return (opt2(as, bs));
	return (FALSE);
}
