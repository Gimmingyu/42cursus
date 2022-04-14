/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ixu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:12:01 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:32:34 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_conversion(va_list ap)
{
	int		num;

	num = va_arg(ap, int);
	return (ft_itoa(num));
}

char	*ui_conversion(va_list ap)
{
	unsigned int	num;
	size_t			size;
	char			*ret;

	num = va_arg(ap, unsigned int);
	size = get_ui_malloc_size(num);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size--] = NUL;
	while (num)
	{
		ret[size--] = '0' + (num % 10);
		num /= 10;
	}
	return (ret);
}

char	*uhexa_conversion(va_list ap)
{
	char			*ret;
	unsigned int	num;
	size_t			size;

	num = va_arg(ap, unsigned int);
	size = get_hexa_malloc_size(num);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size--] = NUL;
	return (ret);
}

char	*lhexa_conversion(va_list ap)
{
	char			*ret;
	unsigned int	num;
	size_t			size;

	num = va_arg(ap, unsigned int);
	size = get_hexa_malloc_size(num);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size--] = NUL;
	return (ret);
}
