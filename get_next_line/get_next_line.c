/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/30 20:44:35 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	int				is_exist;
	char			*ret;

	is_exist = 1;
	if (!flist[fd])
		is_exist = 0;
	if (!is_exist)
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
	else
	{
		ret = read_join(fd, flist[fd]);
		if (!ret || !*ret)
			return (NULL);
		return (ret);
	}
}
