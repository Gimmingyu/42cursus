/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:53:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/29 16:00:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pointer_set	*init_pointer_set(void)
{
	t_pointer_set	*set;

	set = malloc(sizeof(t_pointer_set));
	if (!set)
		exit_on_error();
	set->mlx_ptr = mlx_init();
	if (!(set->mlx_ptr))
		exit_on_error();
	return (set);
}
