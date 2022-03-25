/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/25 21:42:16 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*temp;
	char	buf[BUFFER_SIZE];
	size_t	idx;
	size_t	length;

	if (fd < 0)
		return (NULL);
	length = read(fd, buf, BUFFER_SIZE);
	if (length == -1)
		return (NULL);
	idx = ft_find_newline(buf);
	if (idx == -1)
	{
		temp = ft_strdup(buf, length);
		if (!temp)
			return (NULL);
	}
	return (NULL);
}
