/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:32:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 23:00:33 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_exit(1, "Error: initializing mlx\n");
	game->map = game->map_data->map;
	load_images(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cube3D");
	if (!game->win)
		cleanup_exit(1, "Error: creating window\n");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		cleanup_exit(1, "Error: creating image\n");
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->line_lengh,
			&game->endian);
	if (!game->data)
		cleanup_exit(1, "Error: getting image data address\n");
	calibrate_optics(game->camera);
}

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = my_alloc(sizeof(t_camera), SCOPE_GAME);
	camera->pos_x = -1;
	camera->pos_y = -1;
	camera->view_angle = -1;
	camera->move_fwd = false;
	camera->move_back = false;
	camera->truck_left = false;
	camera->truck_right = false;
	camera->rotate_left = false;
	camera->rotate_right = false;
	return (camera);
}

t_game	*create_game(void)
{
	t_game	*game;

	game = my_alloc(sizeof(t_game), SCOPE_GAME);
	game->map_data = map_init();
	game->camera = init_camera();
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->bpp = -1;
	game->endian = -1;
	game->line_lengh = -1;
	return (game);
}
