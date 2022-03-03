/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:56:36 by dha               #+#    #+#             */
/*   Updated: 2022/03/03 23:55:21 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw_map(t_game *game)
{
	t_coord	coord;

	mlx_put_image_to_window(game->mlx, game->win, game->scr.img, 0, 0);
	coord.y = -1;
	while (++coord.y < game->map.row)
	{
		coord.x = -1;
		while (++coord.x < game->map.column)
		{
			if (game->map.map[coord.y][coord.x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, \
						coord.x * GAME_BIT, coord.y * GAME_BIT);
			else if (game->map.map[coord.y][coord.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game-> \
				collectible.img, coord.x * GAME_BIT, coord.y * GAME_BIT);
			else if (game->map.map[coord.y][coord.x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit.img, \
						coord.x * GAME_BIT, coord.y * GAME_BIT);
			else if (game->map.map[coord.y][coord.x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game-> \
						character.img, coord.x * GAME_BIT, coord.y * GAME_BIT);
		}
	}
}
