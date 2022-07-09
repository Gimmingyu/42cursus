/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:51:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/09 13:52:30 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_sum_of_stack(t_linked_stack *stack)
{
	size_t			idx;
	int				ret;
	t_stack_node	*node;

	ret = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count - 1)
	{
		ret += node->value;
		node = node->next;
	}
	return (ret);
}