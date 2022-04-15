/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:41:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/15 14:48:56 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	void	*fp;
	char	*ret;
	size_t	ret_size;

	ret_size = 0;
	if (!format)
		return (ERR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ret = assign_result(assign_func(&fp, *++format), &ap);
			ret_size += (*(t_func)fp)(ret);
			free_return_line(&ret);
			format++;
		}
		else
		{
			write(1, format, 1);
			ret_size++;
		}
		format++;
	}
	va_end(ap);
	return (ret_size);
}
