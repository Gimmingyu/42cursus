/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_csdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:42:07 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:35:26 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	write_integer(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_char(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}

ssize_t	write_string(char *ret)
{
	return (write(1, ret, get_strlen(ret)));
}
