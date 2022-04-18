/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:37:54 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/23 19:56:44 by mingkim          ###   ########.fr       */
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
