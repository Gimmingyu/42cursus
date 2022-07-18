/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_opt_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:00:05 by mingkim         #+#    #+#             */
/*   Updated: 2022/07/15 22:00:05 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reversed_opt3_case1(t_linked_stack *as, t_linked_stack *bs, long *tmb)
{
	if (tmb[0] < tmb[1] && tmb[1] < tmb[2] && tmb[0] < tmb[2])
	{
		single_rotate(bs, RB);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
		single_reverse_rotate(bs, RRB);
		push(as, bs, PA);
	}
	else if (tmb[0] < tmb[2] && tmb[2] < tmb[1] && tmb[0] < tmb[1])
	{
		single_swap(bs, SB);
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (tmb[2] < tmb[0] && tmb[0] < tmb[1] && tmb[2] < tmb[1])
	{
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
}

void	reversed_opt3_case2(t_linked_stack *as, t_linked_stack *bs, long *tmb)
{
	if (tmb[1] < tmb[2] && tmb[2] < tmb[0] && tmb[1] < tmb[0])
	{
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (tmb[1] < tmb[0] && tmb[0] < tmb[2] && tmb[1] < tmb[2])
	{
		single_rotate(bs, RB);
		single_swap(bs, SB);
		push(as, bs, PA);
		single_reverse_rotate(bs, RRB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
}

void	reversed_actual3_case1(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb)
{
	if (tmb[0] < tmb[2] && tmb[2] < tmb[1] && tmb[0] < tmb[1])
	{
		single_rotate(bs, RB);
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (tmb[0] < tmb[1] && tmb[1] < tmb[2] && tmb[0] < tmb[2])
	{
		single_reverse_rotate(bs, RRB);
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
}

void	reversed_actual3_case2(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb)
{
	if (tmb[1] < tmb[2] && tmb[2] < tmb[0] && tmb[1] < tmb[0])
	{
		push(as, bs, PA);
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (tmb[1] < tmb[0] && tmb[0] < tmb[2] && tmb[1] < tmb[2])
	{
		single_reverse_rotate(bs, RRB);
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
	else if (tmb[2] < tmb[0] && tmb[2] < tmb[1] && tmb[2] < tmb[1])
	{
		single_swap(bs, SB);
		push(as, bs, PA);
		push(as, bs, PA);
		push(as, bs, PA);
	}
}
