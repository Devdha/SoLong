/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:03:29 by dha               #+#    #+#             */
/*   Updated: 2022/03/03 21:36:46 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strncmp(".ber", ft_strrchr(argv[1], '.'), 5)
		|| ft_strlen(argv[1]) < 5)
		ft_error_exit("Error\n Wrong format(./so_long [MAP_FILE].ber)");
	get_map(&game, argv[1]);
	init_img(&game);
}
