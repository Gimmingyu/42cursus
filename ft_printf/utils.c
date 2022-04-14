/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:42:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/14 16:44:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_strlen(const char *str)
{
	size_t	i;
	char	*tmp;

	if (!str)
		return (ERR);
	tmp = (char *)str;
	i = 0;
	while (*tmp)
	{
		tmp++;
		i++;
	}
	return (i);
}

size_t	get_ui_malloc_size(unsigned int num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

size_t	get_hexa_malloc_size(unsigned long long num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

void	free_return_line(char **ret_ptr)
{
	if (*ret_ptr)
		free(*ret_ptr);
	*ret_ptr = NULL;
}