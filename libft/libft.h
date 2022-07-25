/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:38:22 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/19 21:58:51 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>

size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);
#endif
