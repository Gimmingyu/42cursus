/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:17:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/29 16:25:28 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_pointer_set **set_ptr)
{
	(*set_ptr) = malloc(sizeof(t_pointer_set));
	if (!(*set_ptr))
		exit_on_error();
	(*set_ptr)->mlx_ptr = mlx_init();
	if (!(*set_ptr)->mlx_ptr)
		exit_on_error();
	(*set_ptr)->win_ptr = mlx_new_window((*set_ptr)->mlx_ptr, \
							500, 500, "mingkim");
	if (!(*set_ptr)->win_ptr)
		exit_on_error();
}

int	destroy(int keydown, t_pointer_set *pSet)
{
	if (!pSet || !pSet->mlx_ptr || !(pSet->win_ptr))
		exit_on_error();
	if (keydown == ESC_KEY)
		mlx_destroy_window(pSet->mlx_ptr, pSet->win_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_pointer_set	*set;

	validator(ac, av);
	set = init_pointer_set();
	mlx_loop(set->mlx_ptr);
	return (0);
}
