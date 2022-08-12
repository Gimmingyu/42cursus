/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:44:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/12 16:52:46 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	total_move_logger(t_info *info)
{
	char	*sentence;
	char	*count;

	info->mv_count++;
	count = ft_itoa(info->mv_count);
	if (!count)
		exit_on_error("Memory allocate error...\n");
	sentence = ft_strjoin("Total move count : ", count);
	if (!sentence)
		exit_on_error("Memory allocate error...\n");
	write(1, sentence, ft_strlen(sentence));
	write(1, "\n", 1);
	free(sentence);
	free(count);
}

int	game_clear_exit(t_info *info)
{
	char	*sentence;
	char	*count;

	info->mv_count++;
	count = ft_itoa(info->mv_count);
	if (!count)
		exit_on_error("Memory allocate error...\n");
	sentence = ft_strjoin("Your total move count : ", count);
	if (!sentence)
		exit_on_error("Memory allocate error...\n");
	write(1, "Game Clear !!\n", 14);
	write(1, sentence, ft_strlen(sentence));
	write(1, "\n", 1);
	mlx_destroy_window(info->set->mlx_ptr, info->set->win_ptr);
	free(sentence);
	free(count);
	free_all_information(info);
	exit(0);
}

int	esc_game_exit(t_info *info)
{
	mlx_destroy_window(info->set->mlx_ptr, info->set->win_ptr);
	free_all_information(info);
	exit(0);
}

int	keypress_in_game(int keydown, t_info *info)
{
	if (keydown == ESC_KEY)
		esc_game_exit(info);
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
