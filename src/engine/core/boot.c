/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:32:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 21:51:42 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "types.h"
#include <freefire.h>
#include <stdbool.h>

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map = game->whole_map.map;
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cube3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->line_lengh,
			&game->endian);
	calibrate_optics(&game->camera);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

t_camera *init_camera(void)
{
	t_camera *camera;

	camera = my_alloc(sizeof(t_camera), SCOPE_PARSE);
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
