/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:30:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/30 16:43:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	switch_case_about_map(t_map *map)
{
	size_t	r;
	size_t	c;
	size_t	width;
	size_t	height;

	r = -1;
	c = -1;
	width = map->width;
	height = map->height;
	while (++r < height)
	{
		while (++c < width)
		{
			if (map->table[r][c] == PLAYER)
				map->entry_count++;
			else if (map->table[r][c] == EXIT)
				map->exit_count++;
			else if (map->table[r][c] == COLLECTIBLE)
				map->collectible_count++;
			else if (map->table[r][c] != EMPTY && \
						map->table[r][c] != WALL)
				exit_on_error();
		}
		c = -1;
	}
}

void	verify_border(t_map *map)
{
	size_t	r;
	size_t	c;
	size_t	width;
	size_t	height;

	width = map->width;
	height = map->height;
	r = -1;
	c = -1;
	while (++r < height)
	{
		if (r == 0 || r == height - 1)
		{
			while (++c < width)
				if (map->table[r][c] != WALL)
					exit_on_error();
			c = 0;
		}
		else if (map->table[r][0] != WALL || map->table[r][width - 1] != WALL)
			exit_on_error();
	}
}
