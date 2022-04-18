/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:34:09 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 14:02:20 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_char(va_list *ap_ptr)
{
	char	res;

	res = va_arg(*ap_ptr, unsigned int);
	write(1, &res, 1);
	return (1);
}
