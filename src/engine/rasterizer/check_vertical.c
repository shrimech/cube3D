/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:39:46 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/23 21:44:42 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

static int	is_facing_right(double angle)
{
	return (angle < PI / 2 || angle > 3 * PI / 2);
}

static void	init_vertical_intercept(t_game *game, t_ray *ray, t_ray_step *s)
{
	s->px = game->camera->pos_x;
	s->py = game->camera->pos_y;
	ray->is_facing_right = is_facing_right(ray->angle);
	s->x_intercept = floor(s->px / BLOCK) * BLOCK;
	if (ray->is_facing_right)
		s->x_intercept += BLOCK;
	s->y_intercept = s->py
		+ (s->x_intercept - s->px) * tan(ray->angle);
}

static void	init_vertical_steps(t_ray *ray, t_ray_step *s)
{
	s->x_step = BLOCK;
	if (!ray->is_facing_right)
		s->x_step *= -1;
	s->y_step = s->x_step * tan(ray->angle);
	s->next_x = s->x_intercept;
	s->next_y = s->y_intercept;
}

static int	vertical_wall_hit(t_game *game, t_ray *ray, t_ray_step *s)
{
	while (s->next_x >= 0 && s->next_x <= WIDTH
		&& s->next_y >= 0 && s->next_y <= HEIGHT)
	{
		s->check = s->next_x;
		if (!ray->is_facing_right)
			s->check -= 0.001;
		if (is_wall(game, s->check, s->next_y))
		{
			ray->vert_x = s->next_x;
			ray->vert_y = s->next_y;
			ray->vert_dist = distance(s->next_x, s->next_y,
					s->px, s->py);
			return (1);
		}
		s->next_x += s->x_step;
		s->next_y += s->y_step;
	}
	return (0);
}

void	check_vertical(t_game *game, t_ray *ray)
{
	t_ray_step	step;

	init_vertical_intercept(game, ray, &step);
	init_vertical_steps(ray, &step);
	vertical_wall_hit(game, ray, &step);
}
