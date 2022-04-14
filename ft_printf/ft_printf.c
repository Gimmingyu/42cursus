/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:41:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:46:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	void	*fp;
	char	*ret;

	if (!format)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ret = assign_result(assign_func(&fp, *++format), &ap);
			if (!ret)
				return (0);
			(*(t_func)fp)(ret);
			free_return_line(&ret);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (0);
}
