/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/09 19:10:26 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	solution(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	if (!a_stack || !b_stack || is_linked_stack_empty(a_stack))
		return (ERROR);
	return (OK);
}
