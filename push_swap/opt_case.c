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

#include "push_swap.h"

void	opt3_case1(t_linked_stack *as, t_linked_stack *bs, long *tmb)
{
	if (!as || !bs || !tmb || as->element_count < 3)
		response_error();
	if (tmb[0] < tmb[2] && tmb[2] < tmb[1] && tmb[0] < tmb[1])
	{
		push(bs, as, PB);
		single_swap(as, SA);
		push(as, bs, PA);
	}
	else if (tmb[1] < tmb[2] && tmb[2] < tmb[0] && tmb[1] < tmb[0])
	{
		single_swap(as, SA);
		push(bs, as, PB);
		single_swap(as, SA);
		push(as, bs, PA);
	}
	else if (tmb[1] < tmb[0] && tmb[0] < tmb[2] && tmb[1] < tmb[2])
		single_swap(as, SA);
}

void	opt3_case2(t_linked_stack *as, t_linked_stack *bs, long *tmb)
{
	if (!as || !bs || !tmb || as->element_count < 3)
		response_error();
	if (tmb[2] < tmb[1] && tmb[1] < tmb[0] && tmb[2] < tmb[0])
	{
		single_swap(as, SA);
		single_rotate(as, RA);
		single_swap(as, RA);
		single_reverse_rotate(as, RRA);
		single_swap(as, SA);
	}
	else if (tmb[2] < tmb[0] && tmb[0] < tmb[1] && tmb[2] < tmb[1])
	{
		push(bs, as, PB);
		single_swap(as, SA);
		push(as, bs, PA);
		single_swap(as, SA);
	}
}

void	opt_actual3_case1(t_linked_stack *as, t_linked_stack *bs, \
							long *tmb)
{
	if (!as || !bs || !tmb || as->element_count != 3)
		response_error();
	if (tmb[0] < tmb[2] && tmb[2] < tmb[1] && tmb[0] < tmb[1])
	{
		single_swap(as, SA);
		single_rotate(as, RA);
	}
	else if (tmb[1] < tmb[2] && tmb[2] < tmb[0] && tmb[1] < tmb[0])
		single_rotate(as, RA);
	else if (tmb[1] < tmb[0] && tmb[0] < tmb[2] && tmb[1] < tmb[2])
		single_swap(as, SA);
}

void	opt_actual3_case2(t_linked_stack *as, t_linked_stack *bs, \
							long *tmb)
{
	if (!as || !bs || !tmb || as->element_count != 3)
		response_error();
	if (tmb[2] < tmb[0] && tmb[0] < tmb[1] && tmb[2] < tmb[1])
		single_reverse_rotate(as, RRA);
	else if (tmb[2] < tmb[1] && tmb[1] < tmb[0] && tmb[2] < tmb[0])
	{
		single_rotate(as, RA);
		single_swap(as, SA);
	}
}
