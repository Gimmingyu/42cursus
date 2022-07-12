/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:35:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:35:55 by mingkim          ###   ########.fr       */
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
