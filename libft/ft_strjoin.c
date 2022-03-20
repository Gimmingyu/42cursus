/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:56:17 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/17 16:11:35 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 && !s2)
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	else if (!s1 && s2)
	{
		ptr = ft_strdup(s2);
		return (ptr);
	}
	else if (s1 && !s2)
	{
		ptr = ft_strdup(s1);
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(ptr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ptr);
}
