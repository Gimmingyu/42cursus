/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:16:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/25 21:43:34 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (*(buf + i))
	{
		if (*(buf + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *buf, size_t length)
{
	char	*ptr;
	size_t	idx;

	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (*(buf + idx))
		*ptr++ = *(buf + idx++);
	return (ptr);
}
