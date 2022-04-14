/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_xpu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:29:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 15:48:25 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_pointer(char *ret)
{
	if (ret)
		ret = NULL;
}

void	write_lower_hexa(char *ret)
{
	if (ret)
		ret = NULL;
	return ;
}

void	write_upper_hexa(char *ret)
{
	if (ret)
		ret = NULL;
	return ;
}

void	write_unsigned_int(char *ret)
{
	if (ret)
		ret = NULL;
	return ;
}

void	write_percent(char *ret)
{
	if (ret)
		ret = NULL;
	write(1, "%", 1);
}
