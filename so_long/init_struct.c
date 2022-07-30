/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:53:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/30 16:32:53 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pointer_set	*init_pointer_set(t_map *map)
{
	t_pointer_set	*set;

	set = malloc(sizeof(t_pointer_set));
	if (!set)
		exit_on_error();
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, 64 * map->width, \
									64 * map->height, "mingkim mlx");
	return (set);
}

t_map	*init_map(char *line)
{
	t_map	*map;
	int		initial_width;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_on_error();
	initial_width = ft_strlen(line);
	map->width = initial_width;
	map->height = 0;
	map->exit_count = 0;
	map->entry_count = 0;
	map->collectible_count = 0;
	return (map);
}

t_img	*init_img(void *mlx)
{
	t_img	*img;
	int		width;
	int		height;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_on_error();
	img->wall = mlx_xpm_file_to_image(mlx, IMG_WALL, &width, &height);
	img->empty = mlx_xpm_file_to_image(mlx, IMG_EMPTY, &width, &height);
	img->coin = mlx_xpm_file_to_image(mlx, IMG_COIN, &width, &height);
	img->exit = mlx_xpm_file_to_image(mlx, IMG_EXIT, &width, &height);
	img->entry = mlx_xpm_file_to_image(mlx, IMG_ENTRY, &width, &height);
	img->sonic = mlx_xpm_file_to_image(mlx, SONIC_RIGHT1, &width, &height);
	return (img);
}

t_info	*init_information(t_img *img, t_pointer_set *set, t_map *map)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		exit_on_error();
	info->img = img;
	info->set = set;
	info->map = map;
	return (info);
}
