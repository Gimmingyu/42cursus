/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:16:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/16 23:48:40 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_rotate(t_linked_stack *stack, t_command command)
{
	t_stack_node	*top_node;
	t_type			flag;

	if (!stack)
		response_error();
	if (stack->element_count > 1)
	{
		top_node = pop_on_top(stack);
		if (!top_node)
			response_error();
		flag = push_bottom(stack, top_node->value);
		free(top_node);
		if (command == RA && flag == TRUE)
			write(1, "ra\n", 3);
		else if (command == RB && flag == TRUE)
			write(1, "rb\n", 3);
		return (TRUE);
	}
	return (FALSE);
}

int	both_rotate(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_type	ra;
	t_type	rb;

	if (!a_stack || !b_stack)
		response_error();
	ra = single_rotate(a_stack, RR);
	rb = single_rotate(b_stack, RR);
	if (ra == TRUE && rb == TRUE)
		write(1, "rr\n", 3);
	else if (ra == TRUE && rb != TRUE)
		write(1, "ra\n", 3);
	else if (rb == TRUE && ra != TRUE)
		write(1, "ra\n", 3);
	return (TRUE);
}
