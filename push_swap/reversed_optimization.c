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

#include "push_swap.h"

int	reversed_opt_actual3(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!bs || bs->element_count != 3)
		response_error();
	tmb[0] = bs->top_node.next->value;
	tmb[1] = bs->top_node.next->next->value;
	tmb[2] = bs->top_node.prev->value;
	reversed_actual3_case1(as, bs, tmb);
	reversed_actual3_case2(as, bs, tmb);
	return (TRUE);
}

int	reversed_opt3(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!bs)
		response_error();
	tmb[0] = bs->top_node.next->value;
	tmb[1] = bs->top_node.next->next->value;
	tmb[2] = bs->top_node.next->next->value;
	reversed_opt3_case1(as, bs, tmb);
	reversed_opt3_case2(as, bs, tmb);
	if (tmb[0] > tmb[1] && tmb[1] > tmb[2])
	{
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	return (TRUE);
}

int	reversed_opt2(t_linked_stack *as, t_linked_stack *bs)
{
	if (!bs)
		response_error();
	if (bs->top_node.next->value < bs->top_node.next->next->value)
		single_swap(bs, SB);
	push(as, bs, PA);
	push(as, bs, PA);
	return (TRUE);
}

int	b_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k)
{
	if (!as || !bs || k < 0)
		response_error();
	else if (bs->element_count > 3 && k == 3)
		return (reversed_opt3(as, bs));
	else if (bs->element_count == 3 && k == 3)
		return (reversed_opt_actual3(as, bs));
	else if (k == 3 && bs->element_count == 2)
		return (reversed_opt2(as, bs));
	else if (k == 3)
		return (push(as, bs, PA));
	else if (k == 2 && bs->element_count >= 2)
		return (reversed_opt2(as, bs));
	else if (k == 2 || k == 1)
		return (push(as, bs, PA));
	return (TRUE);
}
