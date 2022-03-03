/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:03:50 by dha               #+#    #+#             */
/*   Updated: 2022/03/03 21:28:35 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

# define SCR_COLOR 0xABCDEF

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**map;
	int		row;
	int		column;
	int		cnt_exit;
	int		cnt_collectible;
	int		cnt_start;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		width;
	int		height;
	t_data	scr;
	t_data	wall;
	t_data	exit;
	t_data	collectible;
	t_data	character;
}				t_game;

void	get_map(t_game *game, char *map_file);
void	init_img(t_game *game);

#endif