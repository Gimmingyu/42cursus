/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:17:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/07 19:38:58 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int	single_swap(t_linked_stack *stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	int				temp;

	if (!stack || is_swap_exception(stack) == OK)
		return (FALSE);
	first_node = stack->top_node.next;
	second_node = first_node->next;
	temp = first_node->value;
	first_node->value = second_node->value;
	second_node->value = temp;
	return (OK);
}

int	both_swap(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_stack_node	*a_first_node;
	t_stack_node	*a_second_node;
	t_stack_node	*b_first_node;
	t_stack_node	*b_second_node;
	int				temp;

	if (!a_stack || !b_stack || \
	is_swap_exception(a_stack) || is_swap_exception(b_stack))
		return (FALSE);
	single_swap(a_stack);
	single_swap(b_stack);
	return (OK);
}
