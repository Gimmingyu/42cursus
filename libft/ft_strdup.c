/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:37:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:37:02 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	idx;
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	ptr[idx] = 0x00;
	return (ptr);
}
