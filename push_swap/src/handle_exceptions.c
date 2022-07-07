/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exceptions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:19:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/07 15:23:33 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_swap_exception(t_linked_stack *stack)
{
	if (stack->element_count == 0 || stack->element_count == 1)
		return (OK);
	return (FALSE);
}
