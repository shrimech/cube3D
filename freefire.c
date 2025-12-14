/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:15 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 06:01:22 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"
#include "game.h"
#include "parse.h"
#include <fcntl.h>
#include <minilibx-linux/mlx.h>


int main(void)
{
    t_game game;
    // init
    init_game(&game);
    // hooks
    mlx_hook(game.win, 2, 1L<<0, assert_motion, &game.camera);
    mlx_hook(game.win, 3, 1L<<1, stop_motion, &game.camera);
    // draw loop
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);
    return 0;
}

// int	main(void)
// {
// 	t_map	map;
// 	t_game	game;
//
//
// 	int		fd;
//
// 	fd = open("./maps/map.test.cub", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		ft_exit(NULL);
// 	}
// 	map_init(&map);
// 	map.hole_map = read_map(&map, fd);
// 	if (!map.hole_map)
// 	{
// 		perror("Failed to read map");
// 		ft_exit(&map);
// 	}
// 	parse_hole_map(&map);
// 	print_error();
// 	print_texture(map);
// 	print_colors(map);
// 	print_map(map);
// 	init_game(&game);
// 	mlx_loop(game.mlx);
// }
