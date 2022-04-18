/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:48:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:01:43 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_ptr(va_list *ap_ptr)
{
	char				*ret;
	void				*num;
	unsigned long long	nbr;
	size_t				size;
	int					res;

	num = va_arg(*ap_ptr, void *);
	nbr = (unsigned long long)num;
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
	res = write(1, ret, get_strlen(ret));
	free(ret);
	ret = NULL;
	return (res);
}
