/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/11 16:31:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	divide_groups(t_linked_stack *stack, t_linked_stack *b_stack, \
					t_linked_stack *copied)
{
	t_stack_node	*node;
	t_info			*info;
	size_t			idx;
	int				pivot_a;
	int				pivot_b;

	if (select_pivot(copied, &pivot_a, &pivot_b) == ERROR)
		return (ERROR);
	info = create_info(pivot_a, pivot_b);
	if (!info)
		return (ERROR);
	delete_single_stack(copied);
	free(info);
	return (OK);
}

int	solution(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_info			*info;
	t_linked_stack	*copied;

	if (!a_stack || !b_stack || is_linked_stack_empty(a_stack))
		return (ERROR);
	if (copy_stack(a_stack, &copied) == ERROR)
		return (ERROR);
	bubble_sort(copied);
	set_index(a_stack, copied);
	if (divide_groups(a_stack, b_stack, copied) == ERROR)
	{
		delete_single_stack(copied);
		return (ERROR);
	}
	return (OK);
}
