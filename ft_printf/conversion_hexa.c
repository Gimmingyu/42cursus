/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:38:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:26:20 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_lhexa(unsigned int res)
{
	char	c;
	int		size;

	size = 0;
	if (res)
	{
		c = LHEXA_BASE[res % 16];
		size += write_lhexa(res / 16);
		size += write(1, &c, 1);
	}
	return (size);
}

static int	write_uhexa(unsigned int res)
{
	char	c;
	int		size;

	size = 0;
	if (res)
	{
		c = UHEXA_BASE[res % 16];
		size += write_uhexa(res / 16);
		size += write(1, &c, 1);
	}
	return (size);
}

int	conversion_lhexa(va_list *ap_ptr)
{
	unsigned int	res;
	int				size;

	size = 0;
	res = va_arg(*ap_ptr, unsigned int);
	if (!res)
		return (write(1, "0", 1));
	size += write_lhexa(res);
	return (size);
}

int	conversion_uhexa(va_list *ap_ptr)
{
	unsigned int	res;
	int				size;

	size = 0;
	res = va_arg(*ap_ptr, unsigned int);
	if (!res)
		return (write(1, "0", 1));
	size += write_uhexa(res);
	return (size);
}
