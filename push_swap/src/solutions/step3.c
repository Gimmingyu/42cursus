/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:44:41 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 18:36:17 by mingkim          ###   ########.fr       */
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
	int			count;
	t_command	a_command;
	t_command	b_command;

	if (!a_stack || !b_stack || !info)
		response_error();
	count = 0;
	while (is_linked_stack_empty(b_stack) == FALSE)
	{
		a_command = defind_command_a(a_stack, \
											b_stack->top_node.next->value);
		b_command = define_B_stack_command(b_stack, \
											find_max_value(b_stack));
		if (a_command == RA || b_command == RB)
			;
		else if (a_command == RRA || b_command == RRB)
			;
		else
			;
	}
	return (OK);
}

t_command	defind_command_a(t_linked_stack *stack, int child)
{
	return (RA);
}

t_command	define_command_b(t_linked_stack *stack, int child)
{
	return (RB);
}

int	find_max_value(t_linked_stack *stack)
{
	t_stack_node	*top;
	size_t			idx;
	int				value;

	if (!stack)
		response_error();
	idx = -1;
	value = -2147483648;
	top = stack->top_node.next;
	while (++idx < stack->element_count)
	{
		if (value <= top->value)
			value = top->value;
		top = top->next;
	}
	return (value);
}
