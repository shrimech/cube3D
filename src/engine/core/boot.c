/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:32:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/20 01:14:41 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map = game->hole_map.map;
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cube3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->line_lengh,
			&game->endian);
	calibrate_optics(&game->camera);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
