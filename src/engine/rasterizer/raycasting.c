/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:15:04 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 16:53:29 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <math.h>

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= game->hole_map.width || y < 0
		|| y >= game->hole_map.height)
		return (1);
	map_x = (int)floor(x);
	map_y = (int)floor(y);
	if (game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

// void	check_vertical(t_game *game, t_ray *ray)
// {
// 	double	x_step;
// 	double	y_step;
// 	double	x_intercept;
// 	double	y_intercept;
// 	int		is_facing_right;
// 	int		is_facing_down;
// 	double	next_vert_touch_x;
// 	double	next_vert_touch_y;
//
// 	is_facing_right = (ray->angle < 0.5 * PI || ray->angle > 1.5 * PI);
// 	is_facing_down = (ray->angle > 0 && ray->angle < PI);
//
// }

void	check_horizontal(t_game *game, t_ray *ray)
{
	double	px;
	double	py;
	double	y_step;
	double	x_step;
	double	y_intercept;
	double	x_intercept;
	bool	is_facing_down;
	double	next_x;
	double	next_y;

	px = game->camera.pos_x;
	py = game->camera.pos_y;
	is_facing_down = (ray->angle > 0 && ray->angle < PI);
	if (is_facing_down)
		y_intercept = floor(px / BLOCK) * BLOCK + BLOCK;
	else
		y_intercept = floor(px / BLOCK) * BLOCK - 1;
	x_intercept = (y_intercept - py) / tan(ray->angle) + px;
	y_step = BLOCK;
	if (is_facing_down)
		y_step *= -1;
	x_step = y_step / tan(ray->angle);
	next_y = y_intercept;
	next_x = x_intercept;
	while (next_x >= 0 && next_x <= game->hole_map.width && next_y >= 0
		&& next_y <= game->hole_map.height)
	{
		if (is_wall(game, next_x, next_y))
		{
			ray->horz_x = next_x;
			ray->horz_y = next_y;
			ray->horz_dist = distance(next_x, next_y, px, py);
			return ;
		}
		next_x += x_step;
		next_y += y_step;
	}
}

void check_vertical(t_game *game, t_ray *ray)
{
	double	px;
	double	py;
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
	bool	is_facing_right;
	double	next_x;
	double	next_y;
	
	px = game->camera.pos_x;
	py = game->camera.pos_y;
	is_facing_right = (cos(ray->angle) > 0);
	if (is_facing_right)
		x_intercept = floor(px / BLOCK) * BLOCK + BLOCK;
	else
		x_intercept = floor(px / BLOCK) * BLOCK - 1;
	y_intercept = (x_intercept - px) * tan(ray->angle) + py;
	x_step = BLOCK;
	if (!is_facing_right)
		x_step *= -1;
	y_step = x_step * tan(ray->angle);
	next_x = x_intercept;
	next_y = y_intercept;
	while (next_x >= 0 && next_x <= game->hole_map.width && next_y >= 0
		&& next_y <= game->hole_map.height)
	{
		if (is_wall(game, next_x, next_y))
		{
			ray->vert_x = next_x;
			ray->vert_y = next_y;
			ray->vert_dist = distance(next_x, next_y, px, py);
			return ;
		}
		next_x += x_step;
		next_y += y_step;
	}
}

void	cast_ray(t_game *game, double ray_angle, t_ray *ray)
{
	double	ca;

	ray->angle = normalize_angle(ray_angle);
	ray->horz_dist = 1e30;
	ray->vert_dist = 1e30;
	check_horizontal(game, ray);
	check_vertical(game, ray);
	if (ray->vert_dist < ray->horz_dist)
	{
		ray->distance = ray->vert_dist;
		ray->wall_hit_x = ray->vert_x;
		ray->wall_hit_y = ray->vert_y;
		ray->was_vertical = 1;
	}
	else
	{
		ray->distance = ray->horz_dist;
		ray->wall_hit_x = ray->horz_x;
		ray->wall_hit_y = ray->horz_y;
		ray->was_vertical = 0;
	}
	ca = game->camera.view_angle - ray->angle;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	ray->distance = ray->distance * cos(ca);
}
