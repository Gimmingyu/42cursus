/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:17:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/29 15:47:34 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_ptrs **set_ptr)
{
	(*set_ptr) = malloc(sizeof(t_ptrs));
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

int	destroy(int keydown, t_ptrs *pSet)
{
	if (!pSet || !pSet->mlx_ptr || !(pSet->win_ptr))
		exit_on_error();
	if (keydown == ESC_KEY)
		mlx_destroy_window(pSet->mlx_ptr, pSet->win_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_ptrs	*p_set;
	t_info	info;

	init(&p_set);
	mlx_hook(p_set->win_ptr, X_EVENT_KEY_PRESS, 0, &destroy, p_set);
	info.width = 300;
	info.height = 300;
	info.img = mlx_xpm_file_to_image(p_set->mlx_ptr, SONIC_RIGHT1, \
								&info.width, &info.height);
	mlx_put_image_to_window(p_set->mlx_ptr, p_set->win_ptr, \
								info.img, info.width, info.height);
	mlx_loop(p_set->mlx_ptr);
}
