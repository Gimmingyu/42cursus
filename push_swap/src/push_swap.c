/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/08 17:22:40 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int				length;
	int				*arr;
	t_linked_stack	*a_stack;
	t_linked_stack	*b_stack;

	validator(ac, av);
	create_stacks(&a_stack, &b_stack);
	length = 0;
	while (length++ < ac - 1)
		if (push_bottom(a_stack, ft_atoi(av[length])) == ERROR)
			return (delete_stack(a_stack, b_stack));
	if (is_sorted(a_stack) == OK || is_sorted(a_stack) == ERROR)
		return (delete_stack(a_stack, b_stack));
	solution(a_stack, b_stack);
	display_stack(a_stack);
	display_stack(b_stack);
	system("leaks a.out > leaks_result; cat leaks_result | \
	grep leaked && rm -rf leaks_result");
	return (0);
}
