/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:32:35 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 16:36:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_status status)
{
	if (status == FORK)
		printf("timestamp_in_ms X has taken a fork\n");
	if (status == EATING)
		printf("timestamp_in_ms X is eating\n");
	if (status == SLEEPING)
		printf("timestamp_in_ms X is sleeping\n");
	if (status == THINKING)
		printf("timestamp_in_ms X is thinking\n");
	if (status == DIED)
		printf("timestamp_in_ms X died\n");
}
