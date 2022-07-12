/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:34:31 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:34:33 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*nxt;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		nxt = temp->next;
		ft_lstdelone(temp, del);
		temp = nxt;
	}
	*lst = NULL;
}
