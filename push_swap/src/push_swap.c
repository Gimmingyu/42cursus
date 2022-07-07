/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/07 20:15:00 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr)
{
	*a_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*a_ptr)
		return (ERROR);
	*b_ptr = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!*b_ptr)
	{
		free(a_ptr);
		return (ERROR);
	}
	(*a_ptr)->element_count = 0;
	(*b_ptr)->element_count = 0;
	(*a_ptr)->top_node.prev = NULL;
	(*a_ptr)->top_node.next = NULL;
	(*b_ptr)->top_node.prev = NULL;
	(*b_ptr)->top_node.next = NULL;
	return (OK);
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	return (new_node);
}

int	main(int ac, char **av)
{
	int				length;
	int				*arr;
	t_linked_stack	*a_stack;
	t_linked_stack	*b_stack;

	if (ac == 1 || ac == 2)
		return (0);
	length = 0;
	while (length++ < ac - 1)
		ft_atoi(av[length]);
	if (create_stacks(&a_stack, &b_stack) == ERROR)
		return (response_error());
	while (length++ < ac - 1)
	{
		if (push_bottom(a_stack, ft_atoi(av[length])) == ERROR)
		{
			delete_stack(a_stack);
			delete_stack(b_stack);
			return (0);
		}
	}
	return (0);
}
