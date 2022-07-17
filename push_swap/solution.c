/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:54:35 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_groups(t_linked_stack *stack, t_info **info_ptr, ssize_t count)
{
	long	pivot_a;
	long	pivot_b;

	pivot_a = 0;
	pivot_b = 0;
	if (select_pivot(stack, count, &pivot_a, &pivot_b) == ERROR)
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
	display_stack(as);
	display_stack(bs);
	printf("as->elem= %zu\n", as->element_count);
	printf("bs->elem= %zu\n", bs->element_count);
	return (TRUE);
}

int	a_to_b(t_linked_stack *as, t_linked_stack *bs, ssize_t count)
{
	t_info	*info;

	if (!as || !bs || count < 0)
		response_error();
	if (count <= 3)
		return (a_opt(as, bs, count));
	if (opt5(as, bs) == TRUE)
		return (TRUE);
	divide_groups(as, &info, count);
	if (is_sorted(as, count) != TRUE)
	{
		while (count--)
		{
			if (as->top_node.next->value >= info->pivot_a)
				run_rotate(as, RA, info);
			else
			{
				run_push(as, bs, PB, info);
				if (bs->top_node.next->value >= info->pivot_b)
					run_rotate(bs, RB, info);
			}
		}
		rollback_stacks(as, bs, info);
		a_to_b(as, bs, info->ra_count);
		b_to_a(as, bs, info->rb_count);
		b_to_a(as, bs, info->pb_count - info->rb_count);
	}
	return (free_struct_helper(info, TRUE));
}

int	b_to_a(t_linked_stack *as, t_linked_stack *bs, ssize_t count)
{
	t_info	*info;

	if (!as || !bs || count < 0)
		response_error();
	if (count <= 3)
		return (b_opt(as, bs, count));
	divide_groups(bs, &info, count);
	while (count--)
	{
		if (bs->top_node.next->value < info->pivot_b)
			run_rotate(bs, RB, info);
		else
		{
			run_push(as, bs, PA, info);
			if (as->top_node.next->value < info->pivot_a)
				run_rotate(as, RA, info);
		}
	}
	a_to_b(as, bs, info->pa_count - info->ra_count);
	rollback_stacks(as, bs, info);
	a_to_b(as, bs, info->ra_count);
	b_to_a(as, bs, info->rb_count);
	return (free_struct_helper(info, TRUE));
}

int	rollback_stacks(t_linked_stack *as, t_linked_stack *bs, t_info *info)
{
	ssize_t	ra;
	ssize_t	rb;

	if (!info || !as || !bs)
		response_error();
	ra = 0;
	rb = 0;
	while (info->ra_count > ra || info->rb_count > rb)
	{
		if (info->ra_count > ra && info->rb_count > rb)
			both_reverse_rotate(as, bs);
		else if (info->ra_count > ra && info->rb_count <= rb)
			single_reverse_rotate(as, RRA);
		else if (info->rb_count > rb && info->ra_count <= ra)
			single_reverse_rotate(bs, RRB);
		else
			break ;
		ra++;
		rb++;
	}
	return (TRUE);
}
