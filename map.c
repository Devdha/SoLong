/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:24:07 by dha               #+#    #+#             */
/*   Updated: 2022/03/01 21:55:14 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**get_map(char *map_file)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 2)
		ft_error_exit("[Error] Failed to open map file");
	map = malloc(sizeof(char *) * 8);
	map[0] = get_next_line(fd);
	i = 0;
	while (map[i++])
		map[i] = get_next_line(fd);
	return map;
}