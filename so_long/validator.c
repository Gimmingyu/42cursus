/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:02:14 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/12 17:10:17 by mingkim          ###   ########.fr       */
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
			exit_on_error("Invalid map!!\n");
		i++;
	}
	map->width = width;
	map->height = i;
	return (1);
}

static t_map	*check_map_size(int fd)
{
	t_map	*map;
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		exit_on_error("Function got NULL pointer\n");
	map = init_map(line);
	if (!map)
		exit_on_error("Function got NULL pointer\n");
	while (line)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = string_join(line, temp);
	}
	map->table = ft_split(line, '\n');
	free(line);
	compare_line_length(map);
	return (map);
}

static int	check_map_name(char *str)
{
	size_t	len;

	if (!str)
		exit_on_error("Function got NULL pointer\n");
	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".ber", 4))
		exit_on_error("Not a .ber file\n");
	return (1);
}

static void	verify_map(t_map *map)
{
	if (!map)
		exit_on_error("Function got NULL pointer\n");
	switch_case_about_map(map);
	verify_border(map);
}

t_map	*validator(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac != 2)
		exit_on_error("Too many arguments\n");
	check_map_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_on_error("Got invalid file descriptor\n");
	map = check_map_size(fd);
	close(fd);
	verify_map(map);
	if (map->exit_count < 1 || map->entry_count < 1 \
			|| map->collectible_count < 1 || map->entry_count > 1)
		exit_on_error("Got invalid map\n");
	return (map);
}
