/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_csdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:42:07 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:44:03 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_integer(char *ret)
{
	write(1, ret, get_strlen(ret));
}

void	write_char(char *ret)
{
	write(1, ret, 1);
}

void	write_string(const char *ret)
{
	printf("ret = %s\n", ret);
	printf("size = %td\n", get_strlen(ret));
	write(1, ret, get_strlen(ret));
}
