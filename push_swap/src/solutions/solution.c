/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/08 18:27:28 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pivot으로 sort 하는 함수 
// sort한채로 as와 bs에 반으로 나누어 넣는다.
int	quick_sort(t_linked_stack *as, t_linked_stack *bs, int ap, int bp)
{
	size_t	idx;
	size_t	target_size;
	t_stack_node	*node;

	if (!as || !bs || is_linked_stack_empty(as))
		return (ERROR);
	idx = 0;
	target_size = as->element_count / 2;
	node = as->top_node.next;
	while (idx++ < as->element_count)
	{
		if (node->value != ap && is_greater(bp, node->value))
			push_top()
		if (is_greater(node->value, ap))
			continue ;
		
	}
}

// pivot 찾는 함수
// sort를 한번 하고나서 a의 bottom, b의 top을 pivot으로 잡는다.
int	select_pivot(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	int	random_pivot_a;
	int	random_pivot_b;

	random_pivot_a = a_stack->top_node.next;
	random_pivot_b = a_stack->top_node.prev;
	if (quick_sort(a_stack, b_stack, random_pivot_a, random_pivot_b) == ERROR)
		return (ERROR);
	return (OK);
}

// solution
int	solution(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (select_pivot(a_stack, b_stack) == ERROR)
		return (ERROR);
	return (OK);
}
