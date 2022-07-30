/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:24:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/30 16:43:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "stdio.h"
# include "fcntl.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define WALL '1'

# define SONIC_RIGHT1 "img/sonic_run_ahead_right1.xpm"
# define SONIC_RIGHT2 "img/sonic_run_ahead_right2.xpm"
# define SONIC_RIGHT3 "img/sonic_run_ahead_right3.xpm"
# define SONIC_RIGHT4 "img/sonic_run_ahead_right4.xpm"
# define SONIC_LEFT1 "img/sonic_run_ahead_left1.xpm"
# define SONIC_LEFT2 "img/sonic_run_ahead_left2.xpm"
# define SONIC_LEFT3 "img/sonic_run_ahead_left3.xpm"
# define SONIC_LEFT4 "img/sonic_run_ahead_left4.xpm"

# define IMG_WALL "img/wall.xpm"
# define IMG_EMPTY "img/empty.xpm"
# define IMG_COIN "img/coin.xpm"
# define IMG_EXIT "img/exit.xpm"
# define IMG_ENTRY "img/entry.xpm"

typedef struct s_pointer
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_pointer_set;

typedef struct s_map
{
	int		exit_count;
	int		entry_count;
	int		collectible_count;
	int		width;
	int		height;
	char	**table;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*coin;
	void	*exit;
	void	*entry;
	void	*sonic;
}	t_img;

typedef struct s_game_information
{
	t_img			*img;
	t_map			*map;
	t_pointer_set	*set;
	int				walk_count;
	int				point_count;
}	t_info;

/*********************************************************
***********    Functions for init structure    ***********
*********************************************************/
t_pointer_set	*init_pointer_set(t_map *map);
t_map			*init_map(char *line);
t_img			*init_img(void *mlx);
t_info			*init_information(t_img *img, t_pointer_set *set, t_map *map);
/*********************************************************
***********    Functions for validate data    ************
*********************************************************/
t_map			*validator(int ac, char **av);
void			verify_border(t_map *map);
void			switch_case_about_map(t_map *map);
/*********************************************************
***********    Functions for exit progress    ************
*********************************************************/
int				exit_on_error(void);
/*********************************************************
***********    Functions for rendering map    ************
*********************************************************/
void			render_map(t_map *map, void *mlx, void *win, t_img *img);
/*********************************************************
***********    Functions for game progress    ************
*********************************************************/
int				keypress_in_game(int keycode, t_info *info);
int				keypress_exit_game(int keycode, t_info *info);
#endif