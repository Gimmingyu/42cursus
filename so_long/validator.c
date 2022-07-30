/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:02:14 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/30 15:58:16 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	compare_line_length(t_map *map)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = ft_strlen(map->table[0]);
	while (map->table[i])
	{
		if (ft_strlen(map->table[i]) != width)
			exit_on_error();
		i++;
	}
	map->width = width;
	map->height = i;
	return (1);
}

// Function that verify lines in a file are all the same length
static t_map	*check_map_size(int fd)
{
	t_map	*map;
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		exit_on_error();
	map = init_map(line);
	if (!map)
		exit_on_error();
	while (line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = ft_strjoin(line, temp);
		if (!line)
			exit_on_error();
	}
	map->table = ft_split(line, '\n');
	compare_line_length(map);
	return (map);
}

// Function that file name has .ber at the end.
static int	check_map_name(char *str)
{
	size_t	len;

	if (!str)
		exit_on_error();
	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".ber", 4))
		exit_on_error();
	return (1);
}

// Function that check if the map has a single exit and entry point.
static void	verify_map(t_map *map)
{
	if (!map)
		exit_on_error();
	switch_case_about_map(map);
	verify_border(map);
}

t_map	*validator(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac != 2)
		exit_on_error();
	check_map_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_on_error();
	map = check_map_size(fd);
	close(fd);
	verify_map(map);
	if (map->exit_count < 1 || map->entry_count < 1 \
			|| map->collectible_count < 1)
		exit_on_error();
	return (map);
}
