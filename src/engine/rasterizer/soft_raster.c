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

// void   render_wall(t_game *game, int x, int wall_start, int wall_end)
// {
//        while (wall_start <= wall_end)
//        {
//                put_pixel(x, wall_start, 0xCF4B00, game);
//                wall_start++;
//        }
// }

void	draw_three_d(t_game *game)
{
	t_ray	ray;
	t_wall wall;
	wall.proj_plane_dist = (WIDTH / 2.0) / tan(FOV / 2.0);
	wall.x = 0;
	while (wall.x < WIDTH)
	{
		wall.ray_angle = game->camera->view_angle - (FOV / 2.0) + ((double)wall.x / WIDTH)
			* FOV;
		cast_ray(game, wall.ray_angle, &ray);
		wall.corrected_dist = ray.distance * cos(wall.ray_angle
				- game->camera->view_angle);
		if (wall.corrected_dist < 0.1)
			wall.corrected_dist = 0.1;
		wall.wall_height = (int)((BLOCK / wall.corrected_dist) * wall.proj_plane_dist);
		wall.wall_start = (HEIGHT / 2) - (wall.wall_height / 2);
		if (wall.wall_start < 0)
			wall.wall_start = 0;
		wall.wall_end = (HEIGHT / 2) + (wall.wall_height / 2);
		if (wall.wall_end >= HEIGHT)
			wall.wall_end = HEIGHT - 1;
		// render_wall(game, wall.x, wall.wall_start, wall.wall_end);
		render_wall(game, wall, ray);
		wall.x++;
	}
}

int	draw_loop(t_game *game)
{
	static int	frame_count = 0;

	apply_motion(game, game->camera);
	clear_image(game);
	draw_ceiling_floor(game);
	draw_three_d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (frame_count % 120 == 0)
	{
		printf("Frame %d: player at (%.1f, %.1f), angle: %.2f\n", frame_count,
			game->camera->pos_x, game->camera->pos_y, game->camera->view_angle);
	}
	frame_count++;
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
