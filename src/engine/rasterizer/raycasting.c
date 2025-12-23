/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:15:04 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 21:43:44 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

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
