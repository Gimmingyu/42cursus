/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:45:26 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/10 11:13:37 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player(t_info *info, int *r, int *c)
{
	char	**table;

	table = info->map->table;
	*r = 0;
	while (*r < info->map->height)
	{
		*c = 0;
		while (*c < info->map->width)
		{
			if (table[*r][*c] == PLAYER)
				return ;
			*c += 1;
		}
		*r += 1;
	}
}

int	keypress_right(t_info *info)
{
	char	**table;
	int		r;
	int		c;

	table = info->map->table;
	find_player(info, &r, &c);
	if (c + 1 >= info->map->width || table[r][c + 1] == WALL \
			|| (table[r][c + 1] == EXIT && info->p_count))
		return (0);
	if (table[r][c + 1] == COLLECTIBLE)
		info->p_count--;
	if (table[r][c + 1] == EXIT && info->p_count == 0)
		game_clear_exit(info);
	if (table[r][c + 1] == EMPTY || table[r][c + 1] == COLLECTIBLE)
	{
		table[r][c + 1] = PLAYER;
		table[r][c] = EMPTY;
	}
	render_map(info->map, info->set->mlx_ptr, info->set->win_ptr, info->img);
	return (1);
}

int	keypress_up(t_info *info)
{
	char	**table;
	int		r;
	int		c;

	table = info->map->table;
	find_player(info, &r, &c);
	if (r - 1 < 1 || table[r - 1][c] == WALL \
			|| (table[r - 1][c] == EXIT && info->p_count))
		return (0);
	if (table[r - 1][c] == COLLECTIBLE)
		info->p_count--;
	if (table[r - 1][c] == EXIT && info->p_count == 0)
		game_clear_exit(info);
	if (table[r - 1][c] == EMPTY || table[r - 1][c] == COLLECTIBLE)
	{
		table[r - 1][c] = PLAYER;
		table[r][c] = EMPTY;
	}
	render_map(info->map, info->set->mlx_ptr, info->set->win_ptr, info->img);
	return (1);
}

int	keypress_down(t_info *info)
{
	char	**table;
	int		r;
	int		c;

	table = info->map->table;
	find_player(info, &r, &c);
	if (r + 1 >= info->map->height || table[r + 1][c] == WALL \
		|| (table[r + 1][c] == EXIT && info->p_count))
		return (0);
	if (table[r + 1][c] == COLLECTIBLE)
		info->p_count--;
	if (table[r + 1][c] == EXIT && info->p_count == 0)
		game_clear_exit(info);
	if (table[r + 1][c] == EMPTY || table[r + 1][c] == COLLECTIBLE)
	{
		table[r + 1][c] = PLAYER;
		table[r][c] = EMPTY;
	}
	render_map(info->map, info->set->mlx_ptr, info->set->win_ptr, info->img);
	return (1);
}

int	keypress_left(t_info *info)
{
	char	**table;
	int		r;
	int		c;

	table = info->map->table;
	find_player(info, &r, &c);
	if (c - 1 < 1 || table[r][c - 1] == WALL || \
		(table[r][c - 1] == EXIT && info->p_count))
		return (0);
	if (table[r][c - 1] == COLLECTIBLE)
		info->p_count--;
	if (table[r][c - 1] == EXIT && info->p_count == 0)
		game_clear_exit(info);
	if (table[r][c - 1] == EMPTY || table[r][c - 1] == COLLECTIBLE)
	{
		table[r][c - 1] = PLAYER;
		table[r][c] = EMPTY;
	}
	render_map(info->map, info->set->mlx_ptr, info->set->win_ptr, info->img);
	return (1);
}
