/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 17:46:12 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_linked_stack	*a_stack;
	t_linked_stack	*b_stack;

	create_stacks(&a_stack, &b_stack);
	validator(ac, av, a_stack, b_stack);
	if (is_sorted(a_stack) == OK || is_sorted(a_stack) == ERROR)
		return (delete_all_stack(a_stack, b_stack));
	if (a_optimization(a_stack, b_stack) == FALSE)
		if (solution(a_stack, b_stack) == ERROR)
			response_error();
	delete_all_stack(a_stack, b_stack);
	return (0);
}
