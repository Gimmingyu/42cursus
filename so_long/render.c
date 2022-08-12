/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:37:49 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/12 16:55:09 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *map, void *mlx, void *win, t_img *img)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map->height)
	{
		c = -1;
		while (++c < map->width)
		{
			if (map->table[r][c] == WALL)
				mlx_put_image_to_window(mlx, win, img->wall, c * 64, r * 64);
			else if (map->table[r][c] == EMPTY)
				mlx_put_image_to_window(mlx, win, img->empty, c * 64, r * 64);
			else if (map->table[r][c] == COLLECTIBLE)
				mlx_put_image_to_window(mlx, win, img->coin, c * 64, r * 64);
			else if (map->table[r][c] == EXIT)
				mlx_put_image_to_window(mlx, win, img->exit, c * 64, r * 64);
			else if (map->table[r][c] == PLAYER)
			{
				mlx_put_image_to_window(mlx, win, img->entry, c * 64, r * 64);
				mlx_put_image_to_window(mlx, win, img->sonic, c * 64, r * 64);
			}
		}
	}
}
