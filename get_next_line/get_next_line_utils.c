/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:16:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/29 21:57:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_size(char *str)
{
	size_t	i;

	i = 0;
	while (*str)
		i++;
	return (i);
}

int	find_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (*(buf + i))
		if (*(buf + i++) == '\n')
			return (1);
	return (0);
}

char	*concat(char *content, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = (char *)malloc(sizeof(char) * (get_size(content) + get_size(buf) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(content + i))
	{
		*(ptr + i) = *(content + i);
		i++;
	}
	j = 0;
	while (*(buf + j))
		*(ptr + i++) = *(buf + j++);
	*(ptr + i) = 0x00;
	free(content);
	return (ptr);
}

char	*read_join(int fd, t_file **flist, t_file *file)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	size_t	len;

	buf[BUFFER_SIZE] = 0x00;
	len = read(fd, buf, BUFFER_SIZE);
	while (len != -1 && !find_newline(buf))
	{
		temp = concat(file->content, buf);
		if (!temp)
			return (NULL);
		file->content = temp;
		len = read(fd, buf, BUFFER_SIZE);
	}

}
