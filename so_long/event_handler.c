/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/30 16:44:32 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_exit_game(int keydown, t_info *info)
{
	if (keydown == ESC_KEY)
		mlx_destroy_window(info->set->mlx_ptr, info->set->win_ptr);
	return (0);
}

int	keypress_in_game(int keydown, t_info *info)
{
	if (keydown == W_KEY)
		;
	else if (keydown == A_KEY)
		;
	else if (keydown == S_KEY)
		;
	else if (keydown == D_KEY)
		;
	return (0);
}
