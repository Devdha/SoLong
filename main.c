/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:03:29 by dha               #+#    #+#             */
/*   Updated: 2022/03/01 21:51:12 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2 || ft_strncmp(".ber", ft_strrchr(argv[1], '.'), 5))
		ft_error_exit("[Error] Wrong format(./so_long [MAP_FILE].ber)");
	map = get_map(argv[1]);
	for (int i = 0; map[i]; i++)
		printf("%s", map[i]);
}
