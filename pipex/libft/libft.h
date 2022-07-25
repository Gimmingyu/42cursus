/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:38:22 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/21 22:06:27 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

char	**ft_split(char const *s, char c);
char	**ft_malloc_error(char **arr);
#endif
