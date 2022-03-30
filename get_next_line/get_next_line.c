/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/30 21:34:15 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	char			*ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!flist[fd])
	{
		file = (t_file *)malloc(sizeof(t_file));
		if (!file)
			return (NULL);
		file->content = "";
		file->next = NULL;
		ret = read_join(fd, file);
		if (!ret || !*ret)
			return (NULL);
		flist[fd] = file;
		return (ret);
	}
	ret = read_join(fd, flist[fd]);
	if (!ret || !*ret)
		return (NULL);
	return (ret);
}
