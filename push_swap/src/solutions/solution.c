/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 18:05:51 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	divide_groups(t_linked_stack *stack, t_info **info_ptr)
{
	int				pivot_a;
	int				pivot_b;

	if (select_pivot(stack, &pivot_a, &pivot_b) == ERROR)
		response_error();
	*info_ptr = create_info(pivot_a, pivot_b);
	if (!(*info_ptr))
		response_error();
}

int	solution(t_linked_stack *as, t_linked_stack *bs)
{
	if (!as || !bs || is_linked_stack_empty(as))
		return (ERROR);
	a_to_b(as, bs, as->element_count);
	b_to_a(as, bs, bs->element_count);
	return (OK);
}

int	a_to_b(t_linked_stack *as, t_linked_stack *bs, ssize_t count)
{
	t_info			*info;

	if (!as || !bs || count < 0)
		response_error();
	if (count == 1 || count == 0)
		return (push(bs, as, PB));
	if (count == 5 || count == 3 || count == 2 || \
		count == 1 || count == 0)
		a_optimization(as, bs);
	divide_groups(as, &info);
	while (count--)
	{
		if (as->top_node.next->value >= info->pivot_a)
			run_rotate(as, RA, info);
		else
		{
			run_push(as, bs, PB, info);
			if (bs->top_node.next->value < info->pivot_b)
				run_rotate(bs, RB, info);
		}
	}
	rollback_stacks(as, bs, info);
	a_to_b(as, bs, info->ra_count);
	b_to_a(as, bs, info->rb_count);
	b_to_a(as, bs, info->pb_count - info->rb_count);
	return (free_struct_helper(info, OK));
}

int	b_to_a(t_linked_stack *as, t_linked_stack *bs, ssize_t count)
{
	t_info	*info;

	if (!as || !bs || count < 0)
		response_error();
	if (count == 1 || count == 0)
		return (push(as, bs, PA));
	if (count == 3 || count == 5 || count == 2)
		b_optimization(as, bs);
	divide_groups(bs, &info);
	while (count--)
	{
		if (bs->top_node.next->value < info->pivot_b)
			run_rotate(bs, RB, info);
		else
		{
			run_push(as, bs, PA, info);
			if (as->top_node.next->value >= info->pivot_a)
				run_rotate(as, RA, info);
		}
	}
	rollback_stacks(as, bs, info);
	a_to_b(as, bs, info->ra_count);
	b_to_a(as, bs, info->rb_count);
	return (free_struct_helper(info, OK));
}

int	rollback_stacks(t_linked_stack *as, t_linked_stack *bs, t_info *info)
{
	if (!info || !as || !bs)
		response_error();
	while (info->ra_count > 0 && info->rb_count > 0)
	{
		both_reverse_rotate(as, bs);
		info->ra_count--;
		info->rb_count--;
	}
	return (OK);
}
