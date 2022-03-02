/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:03:29 by dha               #+#    #+#             */
/*   Updated: 2022/03/02 19:33:20 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || ft_strncmp(".ber", ft_strrchr(argv[1], '.'), 5)
		|| ft_strlen(argv[1]) < 5)
		ft_error_exit("Error\n Wrong format(./so_long [MAP_FILE].ber)");
	map = get_map(argv[1]);
}
