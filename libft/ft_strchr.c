/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:36:55 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/23 19:55:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*temp;
	unsigned char	tofind;

	tofind = (unsigned char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == tofind)
			return (temp);
		temp++;
	}
	if (*temp == tofind)
		return (temp);
	return (0);
}
