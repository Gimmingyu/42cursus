/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:57:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/05 13:16:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	collectible_counter(t_info *info)
{
	char	**table;
	int		r;
	int		c;

	table = info->map->table;
	r = -1;
	while (++r < info->map->height)
	{
		c = -1;
		while (++c < info->map->width)
		{
			if (table[r][c] == COLLECTIBLE)
				info->p_count++;
		}
	}
}
