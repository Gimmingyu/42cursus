/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:44:41 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 20:33:01 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
stack a는 항상 정렬되어 있고, b는 느슨한 정렬 상태.

stack b에서 가장 큰 인덱스를 b의 top으로 올린다.
stack a에서 b_top의 index보다 큰 값중 가장 작은 값을 찾아서 맨 위로 올린다.
1: 이 때 ra로 올리는 것과 rra로 올리는 것중 무엇이 빠른지 계산한다. 
2: 계산한 후 ra rb || rra rrb 인 경우에는 rr, rrr을 이용한다.
3: 아니면 개별적으로 실행.
*/
#include "../../include/push_swap.h"

int	step_three(t_linked_stack *a_stack, t_linked_stack *b_stack, t_info *info)
{
	t_command	a_cmd;
	t_command	b_cmd;

	if (!a_stack || !b_stack || !info)
		response_error();
	a_cmd = INIT;
	b_cmd = INIT;
	while (is_linked_stack_empty(b_stack) == FALSE)
	{
		a_cmd = def_command_a(a_stack, find_max_index(b_stack));
		b_cmd = def_command_b(b_stack, find_max_index(b_stack));
		roll_stacks(a_stack, b_stack, a_cmd, b_cmd);
	}
	return (OK);
}

int	roll_stacks(t_linked_stack *as, t_linked_stack *bs, \
					t_command a_cmd, t_command b_cmd)
{
	if (a_cmd == RA && b_cmd == RB)
		return (both_rotate(as, bs));
	if (a_cmd == RRA && b_cmd == RRB)
		return (both_reverse_rotate(as, bs));
	if (a_cmd == NONE && b_cmd == NONE)
		return (push(as, bs, PA));
	if ((a_cmd == RA || a_cmd == NONE) && (b_cmd == NONE || b_cmd == RRB))
	{
		single_rotate(as, a_cmd);
		single_reverse_rotate(bs, b_cmd);
	}
	if ((a_cmd == RRA || a_cmd == NONE) && (b_cmd == NONE || b_cmd == RB))
	{
		single_reverse_rotate(as, a_cmd);
		single_rotate(bs, b_cmd);
	}
	return (OK);
}

t_command	def_command_a(t_linked_stack *stack, int index)
{
	t_stack_node	*node;
	ssize_t			idx;
	ssize_t			target_idx;
	ssize_t			min;

	idx = -1;
	target_idx = 0;
	min = find_max_index(stack);
	node = stack->top_node.next;
	while (++idx < stack->element_count)
	{
		if (node->target_idx <= min && node->target_idx > index)
		{
			min = node->target_idx;
			target_idx = idx;
		}
		node = node->next;
	}
	if (target_idx == 0)
		return (NONE);
	if (target_idx >= stack->element_count / 2)
		return (RRA);
	return (RA);
}

t_command	def_command_b(t_linked_stack *stack, int index)
{
	t_command		command;

	if (!stack || is_linked_stack_empty(stack))
		response_error();
	if (index == 0)
		return (NONE);
	if (index <= stack->element_count / 2)
		return (RB);
	return (RRB);
}

ssize_t	find_max_index(t_linked_stack *stack)
{
	t_stack_node	*top;
	ssize_t			idx;
	ssize_t			target;

	if (!stack)
		response_error();
	idx = -1;
	target = -1;
	top = stack->top_node.next;
	while (++idx < stack->element_count)
	{
		if (target < top->target_idx)
			target = idx;
		top = top->next;
	}
	return (target);
}
