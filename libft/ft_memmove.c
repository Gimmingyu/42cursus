/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:35:48 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:35:49 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*dest_temp;
	unsigned const char	*src_temp;

	if (dest == src || num == 0)
		return (dest);
	if (dest < src)
	{
		dest_temp = dest;
		src_temp = src;
		while (num--)
			*dest_temp++ = *src_temp++;
	}
	else
	{
		dest_temp = dest;
		src_temp = src;
		dest_temp += num;
		src_temp += num;
		while (num--)
			*--dest_temp = *--src_temp;
	}
	return (dest);
}
