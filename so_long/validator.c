/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:02:14 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/29 16:41:16 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function that check if there is single entry point and exit point.
static int	check_map_size(int fd)
{
	char	*line;
	char	*next_line;
	size_t	width;
	size_t	height;

	line = get_next_line(fd);
	if (!line)
		exit_on_error();
	width = ft_strlen(line);
	height = 1;
	while (line)
	{
		next_line = get_next_line(fd);
		if (ft_strlen(line) != width && next_line)
			exit_on_error();
		line = next_line;
		height++;
	}
	return (0);
}

int	validator(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		exit_on_error();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_on_error();
	check_map_size(fd);
	close(fd);
	return (0);
}
