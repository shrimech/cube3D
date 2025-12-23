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

void	draw_three_d(t_game *game)
{
	t_ray	ray;
	t_wall	wall;

	wall.proj_plane_dist = (WIDTH / 2.0) / tan(FOV / 2.0);
	wall.x = 0;
	while (wall.x < WIDTH)
	{
		wall.ray_angle = game->camera->view_angle - (FOV / 2.0)
			+ ((double)wall.x / WIDTH) * FOV;
		cast_ray(game, wall.ray_angle, &ray);
		wall.corrected_dist = ray.distance * cos(wall.ray_angle
				- game->camera->view_angle);
		if (wall.corrected_dist < 0.1)
			wall.corrected_dist = 0.1;
		wall.wall_height = (int)((BLOCK / wall.corrected_dist)
				* wall.proj_plane_dist);
		wall.wall_start = (HEIGHT / 2) - (wall.wall_height / 2);
		if (wall.wall_start < 0)
			wall.wall_start = 0;
		wall.wall_end = (HEIGHT / 2) + (wall.wall_height / 2);
		if (wall.wall_end >= HEIGHT)
			wall.wall_end = HEIGHT - 1;
		render_wall(game, wall, ray);
		wall.x++;
	}
}

int	draw_loop(t_game *game)
{
	apply_motion(game, game->camera);
	clear_image(game);
	draw_ceiling_floor(game);
	draw_three_d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
