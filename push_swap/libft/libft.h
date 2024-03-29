/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:38:22 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/19 21:55:02 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);

size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);
char	**ft_malloc_error(char **arr);
#endif
