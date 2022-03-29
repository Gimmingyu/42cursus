/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/29 21:46:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	t_file			*next_file;
	size_t			idx;

	idx = 0;
	while (flist[idx])
	{
		if (flist[idx]->fd == fd)
		{
			read_join(fd, flist, flist[idx]);
			break ;
		}
		idx++;
	}
	return (NULL);
}
