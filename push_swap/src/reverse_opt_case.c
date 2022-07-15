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

#include "../include/push_swap.h"

int	reverse_opt3_case1(t_linked_stack *stack, long *tmb)
{
	if (!stack)
		response_error();
	if (tmb[0] < tmb[1] && tmb[1] < tmb[2])
	{
		single_swap(stack, SB);
		single_rotate(stack, RB);
		single_swap(stack, SB);
		single_reverse_rotate(stack, RRB);
		single_swap(stack, SB);
	}
	else if (tmb[0] < tmb[2] && tmb[2] < tmb[1])
	{
		single_swap(stack, SB);
		single_rotate(stack, RB);
		single_swap(stack, SB);
		single_reverse_rotate(stack, RRB);
	}
	else if (tmb[2] < tmb[0] && tmb[0] < tmb[1])
		single_swap(stack, SB);
	return (TRUE);
}

int	reverse_opt3_case2(t_linked_stack *stack, long *tmb)
{
	if (!stack)
		response_error();
	// 2 0 1
	if (tmb[1] < tmb[2] && tmb[2] < tmb[0])
	{
		single_rotate(stack, RB);
		single_swap(stack, SB);
		single_reverse_rotate(stack, RRB);
	}
	else if (tmb[1] < tmb[0] && tmb[0] < tmb[2])
	{
		single_rotate(stack, RB);
		single_swap(stack, SB);
		single_reverse_rotate(stack, RRB);
		single_swap(stack, SB);
	}
	return (TRUE);
}