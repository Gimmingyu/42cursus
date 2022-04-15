/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:01:48 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/15 11:45:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	assign_func(void **fp_ptr, char type)
{
	if (type == INT || type == DIGIT)
		*fp_ptr = (t_func)write_integer;
	else if (type == UNSIGNED_INT)
		*fp_ptr = (t_func)write_unsigned_int;
	else if (type == CHAR)
		*fp_ptr = (t_func)write_char;
	else if (type == STRING)
		*fp_ptr = (t_func)write_string;
	else if (type == POINTER)
		*fp_ptr = (t_func)write_pointer;
	else if (type == LOWER_HEXA)
		*fp_ptr = (t_func)write_lower_hexa;
	else if (type == UPPER_HEXA)
		*fp_ptr = (t_func)write_upper_hexa;
	else if (type == PERCENT)
		*fp_ptr = (t_func)write_percent;
	else
	{
		*fp_ptr = NULL;
		return ((t_type)INVALID);
	}
	return ((t_type)type);
}

char	*assign_result(char type, va_list *ap_ptr)
{
	if (type == INT || type == DIGIT)
		return (int_conversion(ap_ptr));
	else if (type == UNSIGNED_INT)
		return (ui_conversion(ap_ptr));
	else if (type == CHAR)
		return (char_conversion(ap_ptr));
	else if (type == STRING)
		return (string_conversion(ap_ptr));
	else if (type == POINTER)
		return (ptr_conversion(ap_ptr));
	else if (type == LOWER_HEXA)
		return (lhexa_conversion(ap_ptr));
	else if (type == UPPER_HEXA)
		return (uhexa_conversion(ap_ptr));
	else if (type == PERCENT)
		return (percent_conversion());
	else
		return (NULL);
}
