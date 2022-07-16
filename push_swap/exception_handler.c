/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:19:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/16 15:04:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_swap_exception(t_linked_stack *stack)
{
	if (stack->element_count == 0 || stack->element_count == 1)
		return (TRUE);
	return (FALSE);
}

int	free_struct_helper(t_info *info, t_type flag)
{
	free(info);
	return (flag);
}

int	response_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
