/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/08 16:34:12 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	total_move_logger(t_info *info)
{
	char	*sentence;

	info->mv_count++;
	sentence = ft_strjoin("total move count : ", ft_itoa(info->mv_count));
	if (!sentence)
		exit_on_error("memory allocate error...\n");
	write(1, sentence, ft_strlen(sentence));
	write(1, "\n", 1);
}

int	game_clear_exit(t_info *info)
{
	char	*sentence;

	info->mv_count++;
	sentence = ft_strjoin("Total move count : ", ft_itoa(info->mv_count));
	if (!sentence)
		exit_on_error("memory allocate error...\n");
	write(1, "Game Clear !!\n", 14);
	write(1, sentence, ft_strlen(sentence));
	write(1, "\n", 1);
	mlx_destroy_window(info->set->mlx_ptr, info->set->win_ptr);
	exit(0);
}

int	keypress_exit_game(t_info *info)
{
	mlx_destroy_window(info->set->mlx_ptr, info->set->win_ptr);
	exit(0);
}

int	keypress_in_game(int keydown, t_info *info)
{
	if (keydown == ESC_KEY)
		keypress_exit_game(info);
	if (keydown == W_KEY)
		if (keypress_up(info))
			total_move_logger(info);
	if (keydown == A_KEY)
		if (keypress_left(info))
			total_move_logger(info);
	if (keydown == S_KEY)
		if (keypress_down(info))
			total_move_logger(info);
	if (keydown == D_KEY)
		if (keypress_right(info))
			total_move_logger(info);
	return (0);
}
