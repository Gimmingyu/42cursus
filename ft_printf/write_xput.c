/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_xput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:29:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:35:52 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	write_pointer(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_lower_hexa(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_upper_hexa(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_unsigned_int(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_percent(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}
