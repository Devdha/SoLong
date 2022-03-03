/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:08:04 by dha               #+#    #+#             */
/*   Updated: 2022/03/03 21:49:36 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_img(t_game	*game)
{
	t_coord	coord;
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, 
			"so_long");
	game->scr.img = mlx_new_image(game->mlx, game->width, game->height);
	game->scr.addr = (int *) mlx_get_data_addr(game->scr.img, &game->scr.
			bits_per_pixel, &game->scr.line_length, &game->scr.endian);
	coord.y = -1;
	while (++coord.y < game->height)
	{
		coord.x = -1;
		while (++coord.x < game->width)
			game->scr.addr[coord.y * game->scr.line_length / 4 + coord.x] =
					SCR_COLOR;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->scr.img,0, 0);
	
}
