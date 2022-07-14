/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:36:43 by mingkim         #+#    #+#             */
/*   Updated: 2022/07/10 22:36:43 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_info	*create_info(int pivot_a, int pivot_b)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->pivot_a = pivot_a;
	info->pivot_b = pivot_b;
	info->ra_count = 0;
	info->rb_count = 0;
	info->pa_count = 0;
	info->pb_count = 0;
	return (info);
}
