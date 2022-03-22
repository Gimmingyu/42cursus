/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:14:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 21:52:05 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	tofind;
	char			*temp;

	temp = (char *)s;
	tofind = (unsigned char)c;
	while (*temp++)
		;
	temp--;
	while (*temp != tofind && --temp != s && *temp)
		;
	if (*temp == tofind)
		return ((char *)temp);
	return (0);
}
