/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:18:19 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 06:19:03 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <minilibx-linux/mlx.h>
#include <stdio.h>

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->line_lengh + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + j, y + i, color, game);
			j++;
		}
		i++;
	}
}

int	draw_loop(t_game *game)
{
	t_camera *camera;
	
	camera = &game->camera;
	calibrate_optics(camera);
	apply_motion(camera);
	draw_square(camera->pos_x, camera->pos_y, 10, 0xFFFF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return 0;
}

// void	drawConsoleSquare(int size)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		for (int j = 0; j < size; j++)
// 		{
// 			printf("* ");
// 		}
// 		printf("\n");
// 	}
// }

