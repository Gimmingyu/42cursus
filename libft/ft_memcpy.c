/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:35:43 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 20:01:19 by mingkim          ###   ########.fr       */
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
