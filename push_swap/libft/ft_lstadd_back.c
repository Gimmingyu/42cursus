/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:34:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/20 19:34:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*temp;

	if (!lst || !n)
		return ;
	temp = *lst;
	if (!temp)
	{
		ft_lstadd_front(lst, n);
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = n;
	return ;
}
