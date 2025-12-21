/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:15 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/15 15:10:49 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"
#include "game.h"
#include "parse.h"
#include <fcntl.h>
#include <minilibx-linux/mlx.h>

int	exit_game(int keycode, t_game *game)
{
	printf("%d was pressed", keycode);
	mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

// int	main(void)
// {
// 	t_game	game;

// 	init_game(&game);
// 	mlx_hook(game.win, ON_DESTROY, 0, exit_game, &game);
// 	mlx_hook(game.win, 2, 1L << 0, assert_motion, &game.camera);
// 	mlx_hook(game.win, 3, 1L << 1, stop_motion, &game.camera);
// 	mlx_loop_hook(game.mlx, draw_loop, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }

int	main(void)
{
	t_map	map;
	t_game	game;


	int		fd;

	fd = open("./maps/map.test.cub", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		ft_exit(NULL);
	}
	map_init(&map);
	map.hole_map = read_map(&map, fd);
	if (!map.hole_map)
	{
		perror("Failed to read map");
		ft_exit(&map);
	}
	parse_hole_map(&map, &game);
	game.hole_map = map;
	printf("%d -------------------------%d\n",game.hole_map.height,game.hole_map.width);
	print_texture(map);
	print_colors(map);
	print_map(map, game.camera);
	init_game(&game);
	mlx_hook(game.win, ON_DESTROY, 0, exit_game, &game);
	mlx_hook(game.win, 2, 1L << 0, assert_motion, &game.camera);
	mlx_hook(game.win, 3, 1L << 1, stop_motion, &game.camera);
	game.map = map.map;
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
