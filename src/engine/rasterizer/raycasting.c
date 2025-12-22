/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:15:04 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/21 23:23:55 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <math.h>

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= game->map_data->width || y < 0
		|| y >= game->map_data->height)
		return (1);
	map_x = (int)floor(x);
	map_y = (int)floor(y);
	if (game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	check_vertical(t_game *game, t_ray *ray)
{
	t_ray_step	step;

	step.px = game->camera->pos_x;
	step.py = game->camera->pos_y;
	step.is_facing_right = (ray->angle < PI / 2 || ray->angle > 3 * PI / 2);
	step.x_intercept = floor(step.px / BLOCK) * BLOCK;
	if (step.is_facing_right)
		step.x_intercept += BLOCK;
	step.y_intercept = step.py + (step.px - step.x_intercept) * tan(ray->angle);
	step.x_step = BLOCK;
	if (!step.is_facing_right)
		step.x_step *= -1;
	step.y_step = step.x_step * tan(ray->angle);
	step.next_x = step.x_intercept;
	step.next_y = step.y_intercept;
	while (step.next_x >= 0 && step.next_x <= WIDTH && step.next_y >= 0
		&& step.next_y <= HEIGHT)
	{
		step.check = step.next_y;
		if (!step.is_facing_right)
			step.check -= 1;
		if (is_wall(game, step.next_x, step.check))
		{
			ray->vert_x = step.next_x;
			ray->vert_y = step.next_y;
			ray->vert_dist = distance(step.next_x, step.next_y, step.px,
					step.py);
			return ;
		}
		step.next_x += step.x_step;
		step.next_y += step.y_step;
	}
}

void	check_horizontal(t_game *game, t_ray *ray)
{
	t_ray_step	step;

	step.px = game->camera->pos_x;
	step.py = game->camera->pos_y;
	step.is_facing_down = (ray->angle > 0 && ray->angle < PI);
	step.y_intercept = floor(step.py / BLOCK) * BLOCK;
	if (step.is_facing_down)
		step.y_intercept += BLOCK;
	step.x_intercept = step.px + (step.y_intercept - step.py) / tan(ray->angle);
	step.y_step = BLOCK;
	if (!step.is_facing_down)
		step.y_step *= -1;
	step.x_step = step.y_step / tan(ray->angle);
	step.next_y = step.y_intercept;
	step.next_x = step.x_intercept;
	while (step.next_x >= 0 && step.next_x <= WIDTH && step.next_y >= 0
		&& step.next_y <= HEIGHT)
	{
		step.check = step.next_y;
		if (!step.is_facing_down)
			step.check -= 1;
		if (is_wall(game, step.next_x, step.check))
		{
			ray->horz_x = step.next_x;
			ray->horz_y = step.next_y;
			ray->horz_dist = distance(step.next_x, step.next_y, step.px,
					step.py);
			return ;
		}
		step.next_x += step.x_step;
		step.next_y += step.y_step;
	}
}

void	cast_ray(t_game *game, double ray_angle, t_ray *ray)
{
	ray->angle = normalize_angle(ray_angle);
	ray->horz_dist = 1e30;
	ray->vert_dist = 1e30;
	check_horizontal(game, ray);
	check_vertical(game, ray);
	ray->distance = fmin(ray->vert_dist, ray->horz_dist);
	if (ray->vert_dist < ray->horz_dist)
	{
		ray->wall_hit_x = ray->vert_x;
		ray->wall_hit_y = ray->vert_y;
		ray->was_vertical = true;
	}
	else
	{
		ray->wall_hit_x = ray->horz_x;
		ray->wall_hit_y = ray->horz_y;
		ray->was_vertical = false;
	}
}
