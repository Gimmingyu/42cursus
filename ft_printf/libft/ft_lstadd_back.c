/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:50:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/16 20:20:58 by mingkim          ###   ########.fr       */
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
