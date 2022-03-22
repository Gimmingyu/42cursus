/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:48:43 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/14 19:46:38 by mingkim          ###   ########.fr       */
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
