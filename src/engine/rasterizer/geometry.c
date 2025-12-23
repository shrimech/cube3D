/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:37:34 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 21:50:01 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

double	distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt(dx * dx + dy * dy));
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x) / BLOCK;
	map_y = (int)(y) / BLOCK;
	if (map_x < 0 || map_x >= game->map_data->width || map_y < 0
		|| map_y >= game->map_data->height)
		return (1);
	if (game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
