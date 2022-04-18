/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:11:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/18 19:21:42 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_func(void **fp_ptr, char type)
{
	if (type == INT || type == DIGIT)
		*fp_ptr = (t_func)conversion_int;
	else if (type == CHAR)
		*fp_ptr = (t_func)conversion_char;
	else if (type == STRING)
		*fp_ptr = (t_func)conversion_string;
	else if (type == POINTER)
		*fp_ptr = (t_func)conversion_ptr;
	else if (type == LOWER_HEXA)
		*fp_ptr = (t_func)conversion_lhexa;
	else if (type == UPPER_HEXA)
		*fp_ptr = (t_func)conversion_uhexa;
	else if (type == UNSIGNED_INT)
		*fp_ptr = (t_func)conversion_uint;
	else
		return (ERR);
	return (OK);
}
