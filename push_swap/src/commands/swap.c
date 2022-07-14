/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:17:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 15:48:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	single_swap(t_linked_stack *stack, t_command command)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	int				temp;

	if (!stack)
		response_error();
	if (is_swap_exception(stack) || command == NONE)
		return (OK);
	first_node = stack->top_node.next;
	second_node = first_node->next;
	temp = first_node->value;
	first_node->value = second_node->value;
	second_node->value = temp;
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	return (OK);
}

int	both_swap(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack)
		response_error();
	single_swap(a_stack, SS);
	single_swap(b_stack, SS);
	write(1, "ss\n", 3);
	return (OK);
}
