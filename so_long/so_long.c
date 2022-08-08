/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:17:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/08 16:31:01 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_pointer_set	*set;
	t_map			*map;
	t_img			*img;
	t_info			*info;

	map = validator(ac, av);
	set = init_pointer_set(map);
	img = init_img(set->mlx_ptr);
	render_map(map, set->mlx_ptr, set->win_ptr, img);
	info = init_information(img, set, map);
	mlx_hook(set->win_ptr, X_EVENT_KEY_PRESS, 0, &keypress_in_game, info);
	mlx_hook(set->win_ptr, X_EVENT_KEY_EXIT, 0, &keypress_exit_game, info);
	mlx_loop(set->mlx_ptr);
	return (0);
}
