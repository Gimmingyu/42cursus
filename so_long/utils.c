/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:57:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/08 16:38:32 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_on_error(char *str)
{
	write(2, str, ft_strlen(str));
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
