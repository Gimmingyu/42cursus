/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:21 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:09:44 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_string(va_list *ap_ptr)
{
	char	*res;
	int		size;

	res = va_arg(*ap_ptr, char *);
	if (!res)
		return (write(1, "(null)", 6));
	size = get_strlen(res);
	write(1, res, size);
	return (size);
}
