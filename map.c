/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:24:07 by dha               #+#    #+#             */
/*   Updated: 2022/03/04 16:19:00 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	map_realloc(t_map *map, int pre_size, int new_size)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * new_size);
	i = 0;
	while (i <= pre_size && i <= new_size)
	{
		tmp[i] = map->map[i];
		i++;
	}
	free(map->map);
	map->map = tmp;
	map->row = new_size;
}

static void	check_char(t_map *map, char	c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_error_exit("Error\n Invalid map(must use specified char)");
	if (c == 'E')
		map->cnt_exit++;
	else if (c == 'P')
		map->cnt_start++;
	else if (c == 'C')
		map->cnt_collectible++;
}

static void	check_map(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->column)
		{
			if (((y == 0 || y == map->row - 1) && map->map[y][x] != '1')
				|| ((x == 0 || x == map->column - 1) && map->map[y][x] != '1'))
				ft_error_exit("Error\n Invalid map(must be closed by walls)");
			check_char(map, map->map[y][x]);
			x++;
		}
		y++;
	}
	if (map->cnt_exit < 1)
		ft_error_exit("Error\n Invalid map(must have at lease 1 exit)");
	if (map->cnt_start < 1 || map->cnt_start > 1)
		ft_error_exit("Error\n Invalid map(must have just 1 start point)");
	if (map->cnt_collectible < 1)
		ft_error_exit("Error\n Invalid map(must have at lease 1 collectible)");
}

static void	read_map(t_map *map, int fd)
{
	int	i;

	map->map = malloc(sizeof(char *) * 8);
	map->row = 8;
	if (!(map->map))
		ft_error_exit("Error\n Memory allocation failed");
	map->map[0] = get_next_line(fd);
	if (!map->map[0])
		ft_error_exit("Error\n Empty map");
	map->column = ft_strlen(map->map[0]) - 1;
	map->map[0][map->column] = '\0';
	i = 0;
	while (map->map[i++])
	{
		if (i == map->row)
			map_realloc(map, map->row, map->row * 2);
		map->map[i] = get_next_line(fd);
		if (map->map[i])
		{
			if (map->column != (int) ft_strlen(map->map[i]) - 1)
				ft_error_exit("Error\n Invalid map(must be rectangle)");
			map->map[i][map->column] = '\0';
		}
	}
	map_realloc(map, map->row, i - 1);
}

void	get_map(t_game *game, char *map_file)
{
	t_map	map;
	int		fd;

	ft_bzero(&map, sizeof(map));
	fd = open(map_file, O_RDONLY);
	if (fd < 2)
		ft_error_exit("Error\n Failed to open map file");
	read_map(&map, fd);
	check_map(&map);
	close(fd);
	game->init = 0;
	game->map = map;
	game->width = map.column * GAME_BIT;
	game->height = map.row * GAME_BIT;
}
