/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:11:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 17:18:12 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	run_rotate(t_linked_stack *stack, t_command cmd, t_info *info)
{
	if (!stack || !info)
		response_error();
	if (cmd == RA)
	{
		single_rotate(stack, RA);
		info->ra_count++;
		return (OK);
	}
	else if (cmd == RB)
	{
		single_rotate(stack, RB);
		info->rb_count++;
		return (OK);
	}
	return (response_error());
}

int	run_push(t_linked_stack *as, t_linked_stack *bs, \
				t_command cmd, t_info *info)
{
	if (!as || !bs || !info)
		response_error();
	if (cmd == PA)
	{
		push(as, bs, PA);
		info->pa_count++;
		return (OK);
	}
	else if (cmd == PB)
	{
		push(bs, as, PB);
		info->pb_count++;
		return (OK);
	}
	return (response_error());
}
