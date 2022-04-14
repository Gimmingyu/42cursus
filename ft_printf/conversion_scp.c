/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_scp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:15:56 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:41:22 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_conversion(va_list *ap_ptr)
{
	char	*ret;
	char	c;

	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	c = va_arg(*ap_ptr, int);
	ret[0] = c;
	ret[1] = NUL;
	return (ret);
}

char	*string_conversion(va_list *ap_ptr)
{
	char	*ret;
	char	*temp;

	temp = va_arg(*ap_ptr, char *);
	ret = ft_strdup(temp);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*ptr_conversion(va_list *ap_ptr)
{
	char				*ret;
	unsigned long long	num;
	size_t				size;

	num = va_arg(*ap_ptr, unsigned long long);
	size = get_hexa_malloc_size(num);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size--] = NUL;
	return (ret);
}
