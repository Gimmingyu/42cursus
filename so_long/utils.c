/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:57:39 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/12 16:53:07 by mingkim          ###   ########.fr       */
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

char	*string_join(char *s1, char *s2)
{
	char	*ret;

	if (!s1 || !s2)
		exit_on_error("Function got NULL pointer\n");
	ret = ft_strjoin(s1, s2);
	if (!ret)
		exit_on_error("Function got NULL pointer\n");
	free(s1);
	free(s2);
	return (ret);
}

void	free_all_information(t_info *info)
{
	int	r;

	r = -1;
	while (++r < info->map->height)
		free(info->map->table[r]);
	free(info->map->table);
	free(info->map);
	free(info->set);
	free(info->img->coin);
	free(info->img->wall);
	free(info->img->empty);
	free(info->img->exit);
	free(info->img->entry);
	free(info->img->sonic);
	free(info->img);
	free(info);
}
