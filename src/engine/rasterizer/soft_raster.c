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

#include "game.h"
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

void	render_wall(t_game *game, int x, int wall_start, int wall_end)
{
	while (wall_start <= wall_end)
	{
		put_pixel(x, wall_start, 0xCF4B00, game);
		wall_start++;
	}
}

void	draw_three_d(t_game *game)
{
	t_ray	ray;
	double	ray_angle;
	double	corrected_dist;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		x;
	double	proj_plane_dist;

	proj_plane_dist = (WIDTH / 2.0) / tan(FOV / 2.0);
	x = 0;
	while (x < WIDTH)
	{
		ray_angle = game->camera->view_angle - (FOV / 2.0) + ((double)x / WIDTH)
			* FOV;
		cast_ray(game, ray_angle, &ray);
		corrected_dist = ray.distance * cos(ray_angle
				- game->camera->view_angle);
		if (corrected_dist < 0.1)
			corrected_dist = 0.1;
		wall_height = (int)((BLOCK / corrected_dist) * proj_plane_dist);
		wall_start = (HEIGHT / 2) - (wall_height / 2);
		if (wall_start < 0)
			wall_start = 0;
		wall_end = (HEIGHT / 2) + (wall_height / 2);
		if (wall_end >= HEIGHT)
			wall_end = HEIGHT - 1;
		render_wall(game, x, wall_start, wall_end);
		x++;
	}
}

// void	draw_three_d(t_game *game)
// {
// 	t_ray	ray;
// 	double	s_angle;
// 	double	e_angle;
// 	int		wall_lenght;
// 	int		wall_start;
// 	int		wall_end;
// 	int x;
//
// 	x = 0;
// 	s_angle = game->camera->view_angle - FOV / 2;
// 	e_angle = game->camera->view_angle + FOV / 2;
// 	while (s_angle <= e_angle)
// 	{
// 		cast_ray(game, s_angle, &ray);
// 		wall_lenght = HEIGHT / ray.distance;
// 		wall_start = (HEIGHT / 2) - (wall_lenght / 2);
// 		wall_end = (HEIGHT / 2) + (wall_lenght / 2);
// 		render_wall(game, x, wall_start, wall_end);
// 		x++;
// 		s_angle += STEP_ANGLE;
// 	}
// }

int	draw_loop(t_game *game)
{
	apply_motion(game, game->camera);
	clear_image(game);
	draw_ceiling_floor(game);
	draw_three_d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

/* 	static int	frame_count = 0; */

// if (frame_count % 120 == 0)
// {
// 	printf("Frame %d: player at (%.1f, %.1f), angle: %.2f\n", frame_count,
// 		game->camera->pos_x, game->camera->pos_y, game->camera->view_angle);
// }
// frame_count++;

// void	draw_map(t_game *game)
// {
// 	char	**map;
// 	int		y;
// 	int		x;
//
// 	map = game->map;
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '1')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x234C6A, game);
// 			else if (map[y][x] == '0')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
// 			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
// 				|| map[y][x] == 'W')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
// 			else if (map[y][x] == ' ')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x222222, game);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_square(int x, int y, int size, int color, t_game *game)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			put_pixel(x + j, y + i, color, game);
// 			j++;
// 		}
// 		i++;
// 	}
// }
//
