/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:22:02 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:24:20 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_uint(unsigned int res)
{
	char	c;
	int		size;

	size = 0;
	if (res)
	{
		c = BASE[res % 10];
		size += write_uint(res / 10);
		size += write(1, &c, 1);
	}
	else
		return (0);
	return (size);
}

int	conversion_int(va_list *ap_ptr)
{
	int		res;
	char	*result;

	result = ft_itoa(va_arg(*ap_ptr, int));
	res = get_strlen(result);
	write(1, result, res);
	free(result);
	result = NULL;
	return (res);
}

int	conversion_uint(va_list *ap_ptr)
{
	unsigned int	res;
	int				size;

	size = 0;
	res = va_arg(*ap_ptr, unsigned int);
	if (!res)
		return (write(1, "0", 1));
	size += write_uint(res);
	return (size);
}
