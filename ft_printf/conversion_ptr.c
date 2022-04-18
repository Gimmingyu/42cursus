/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:48:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 19:57:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_ptr_malloc_size(unsigned long long nbr_temp)
{
	size_t				size;

	size = 2;
	if (nbr_temp == 0)
		return (3);
	while (nbr_temp)
	{
		nbr_temp /= 16;
		size++;
	}
	return (size);
}

int	conversion_ptr(va_list *ap_ptr)
{
	char				*ret;
	unsigned long long	nbr;
	size_t				size;
	int					res;

	nbr = (unsigned long long)va_arg(*ap_ptr, void *);
	size = get_ptr_malloc_size(nbr);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[0] = '0';
	ret[1] = 'x';
	ret[2] = '0';
	ret[size--] = NUL;
	while (nbr)
	{
		ret[size--] = LHEXA_BASE[nbr % 16];
		nbr /= 16;
	}
	res = ft_strlen(ret);
	write(1, ret, res);
	free(ret);
	ret = NULL;
	return (res);
}
