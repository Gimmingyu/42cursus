/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:24:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/29 15:47:52 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "stdio.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define SONIC_RIGHT1 "img/sonic_run_ahead_right1.xpm"
# define SONIC_RIGHT2 "img/sonic_run_ahead_right2.xpm"
# define SONIC_RIGHT3 "img/sonic_run_ahead_right3.xpm"
# define SONIC_RIGHT4 "img/sonic_run_ahead_right4.xpm"
# define SONIC_LEFT1 "img/sonic_run_ahead_left1.xpm"
# define SONIC_LEFT2 "img/sonic_run_ahead_left2.xpm"
# define SONIC_LEFT3 "img/sonic_run_ahead_left3.xpm"
# define SONIC_LEFT4 "img/sonic_run_ahead_left4.xpm"

typedef struct s_ptr_var_set
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_ptrs;

typedef struct s_map
{
	int	exit_count;
	int	entry_count;
	int	collectible_count;
	int	width;
	int	height;
}	t_map;

typedef struct s_information
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_of_line;
	int		width;
	int		height;
	int		endian;
}	t_info;

int	exit_on_error(void);

#endif