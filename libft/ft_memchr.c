/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:35:30 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:35:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	tofind;

	temp = (unsigned char *)s;
	tofind = (unsigned char)c;
	while (n--)
	{
		if (*temp == tofind)
			return ((void *)temp);
		temp++;
	}
	return (0);
}
