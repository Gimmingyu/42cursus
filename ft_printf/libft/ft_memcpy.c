/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:16:04 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/13 20:26:49 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (!dest && !src)
		return (NULL);
	dst_temp = dest;
	src_temp = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		*(dst_temp + idx) = *(src_temp + idx);
		idx++;
	}
	return (dest);
}
