/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:17:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/18 15:11:44 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_swap(t_linked_stack *stack, t_command command)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	long			temp;

	if (!stack)
		response_error();
	first_node = stack->top_node.next;
	second_node = stack->top_node.next->next;
	temp = first_node->value;
	first_node->value = second_node->value;
	second_node->value = temp;
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	return (TRUE);
}

int	both_swap(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_type	sa;
	t_type	sb;

	if (!a_stack || !b_stack)
		response_error();
	sa = single_swap(a_stack, SS);
	sb = single_swap(b_stack, SS);
	if (sa == TRUE && sb == TRUE)
		write(1, "ss\n", 3);
	else if (sa == TRUE && sb == FALSE)
		write(1, "sa\n", 3);
	else if (sb == TRUE && sa == FALSE)
		write(1, "sb\n", 3);
	return (TRUE);
}
