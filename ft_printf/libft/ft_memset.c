/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:32:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/10 16:16:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			idx;
	unsigned char	cpy;
	unsigned char	*temp;

	idx = 0;
	temp = ptr;
	cpy = value;
	while (idx++ < len)
		*temp++ = cpy;
	return (ptr);
}
