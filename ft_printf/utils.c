/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:42:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/13 21:40:22 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_output(size_t len, const char *str)
{
	write(1, str, len);
}

size_t	get_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (ERR);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	type_check(char type)
{

	void (*fp)(char);

	if (type == INT || type == DIGIT)
		fp = write_integer(type);
	else if (type == UNSIGNED_INT)
		return ;
	else if (type == CHAR)
		return ;
	else if (type == STRING)
		return ;
	else if (type == POINTER)
		return ;
	else if (type == LOWER_HEXA || type == UPPER_HEXA)
		return ;
}
