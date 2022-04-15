/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_scp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:15:56 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:52:27 by mingkim          ###   ########.fr       */
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
	c = va_arg(*ap_ptr, unsigned int);
	ret[0] = c;
	ret[1] = NUL;
	return (ret);
}

char	*string_conversion(va_list *ap_ptr)
{
	char	*ret;
	char	*temp;

	temp = va_arg(*ap_ptr, char *);
	if (!temp)
		return (ft_strdup("(null) "));
	ret = ft_strdup(temp);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*ptr_conversion(va_list *ap_ptr)
{
	char				*ret;
	void				*num;
	unsigned long long	nbr;
	size_t				size;

	num = va_arg(*ap_ptr, void *);
	nbr = (unsigned long long)num;
	size = get_ptr_malloc_size(nbr);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[2] = '0';
	ret[size--] = NUL;
	while (nbr)
	{
		ret[size--] = LHEXA_BASE[nbr % 16];
		nbr /= 16;
	}
	return (ret);
}
