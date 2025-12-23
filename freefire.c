/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:15 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 23:11:27 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

static int	exit_game(int keycode, t_game *game)
{
	(void)game;
	(void)keycode;
	cleanup_exit(0, "");
	return (0);
}

static void	cub_extantion(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".cub", 5) != 0)
	{
		write(2, "Error: Invalid file extension. Expected .cub\n", 45);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;

	if (ac != 2)
		return (write(2, "Usage: ./cub3D <map_file>\n", 26), 1);
	cub_extantion(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: opening file", 19), 1);
	game = create_game();
	collector_init(game);
	game->map_data->file_buffer = read_map(game->map_data, fd);
	parse_hole_map(game->map_data, game);
	init_graphics(game);
	mlx_hook(game->win, ON_DESTROY, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, assert_motion, game->camera);
	mlx_hook(game->win, 3, 1L << 1, stop_motion, game->camera);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
}
