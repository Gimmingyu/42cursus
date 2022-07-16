/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/16 16:06:44 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	t_linked_stack	*a_stack;
	t_linked_stack	*b_stack;

	create_stacks(&a_stack, &b_stack);
	validator(ac, av, a_stack, b_stack);
	check_duplicate_elem(a_stack);
	if (is_sorted(a_stack) == TRUE || is_sorted(a_stack) == ERROR)
		return (delete_all_stack(a_stack, b_stack));
	if (a_opt(a_stack, b_stack, a_stack->element_count) == FALSE)
		if (solution(a_stack, b_stack) == ERROR)
			response_error();
	delete_all_stack(a_stack, b_stack);
	return (0);
}
