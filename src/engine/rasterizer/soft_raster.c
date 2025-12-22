/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:18:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 20:00:59 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

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

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x234C6A, game);
			else if (map[y][x] == '0')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
			else if (map[y][x] == ' ')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x222222, game);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_game *game)
{

	static int	frame_count = 0;


	apply_motion(game, game->camera);
	clear_image(game);
	draw_map(game);
	draw_square(game->camera->pos_x, game->camera->pos_y, 10, 0xFF0000, game);
	// Draw rays in the range of the FOV in front of the player, stopping at walls
	{
		int num_rays = 100; // Number of rays to draw for FOV visualization
		double half_fov = FOV / 2.0;
		int x0 = (int)(game->camera->pos_x + 5);
		int y0 = (int)(game->camera->pos_y + 5);
		for (int i = 0; i < num_rays; i++) {
			double ratio = (double)i / (num_rays - 1);
			double ray_angle = game->camera->view_angle - half_fov + ratio * FOV;
			double ray_dx = cos(ray_angle);
			double ray_dy = sin(ray_angle);
			double cur_x = game->camera->pos_x + 5;
			double cur_y = game->camera->pos_y + 5;
			// int hit = 0;
			float max_steps = INFINITY; // max ray length in pixels
			for (int step = 0; step < max_steps; step++) {
				int map_x = (int)(cur_x) / BLOCK;
				int map_y = (int)(cur_y) / BLOCK;
				if (map_y < 0 || map_x < 0 || !game->map || !game->map[map_y] || game->map[map_y][map_x] == '1') {
					// hit = 1;
					break;
				}
				cur_x += ray_dx;
				cur_y += ray_dy;
			}
			int x1 = (int)cur_x;
			int y1 = (int)cur_y;
			draw_line(x0, y0, x1, y1, 0x00FF00, game); // green rays
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->images[1].img_ptr, 0, 0);
	if (frame_count % 120 == 0)
	{
		printf("Frame %d: player at (%.1f, %.1f), angle: %.2f\n", frame_count,
			game->camera->pos_x, game->camera->pos_y, game->camera->view_angle);
	}
	frame_count++;
	return (0);
}
