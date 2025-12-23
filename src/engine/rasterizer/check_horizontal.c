/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:38:52 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/23 21:45:11 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

static int	is_facing_down(double angle)
{
	return (angle > 0 && angle < PI);
}

static void	init_horizontal_intercept(t_game *game, t_ray *ray, t_ray_step *s)
{
	s->px = game->camera->pos_x;
	s->py = game->camera->pos_y;
	ray->is_facing_down = is_facing_down(ray->angle);
	s->y_intercept = floor(s->py / BLOCK) * BLOCK;
	if (ray->is_facing_down)
		s->y_intercept += BLOCK;
	s->x_intercept = s->px
		+ (s->y_intercept - s->py) / tan(ray->angle);
}

static void	init_horizontal_steps(t_ray *ray, t_ray_step *s)
{
	s->y_step = BLOCK;
	if (!ray->is_facing_down)
		s->y_step *= -1;
	s->x_step = s->y_step / tan(ray->angle);
	s->next_y = s->y_intercept;
	s->next_x = s->x_intercept;
}

static int	horizontal_wall_hit(t_game *game, t_ray *ray, t_ray_step *s)
{
	while (s->next_x >= 0 && s->next_x <= WIDTH
		&& s->next_y >= 0 && s->next_y <= HEIGHT)
	{
		s->check = s->next_y;
		if (!ray->is_facing_down)
			s->check -= 0.001;
		if (is_wall(game, s->next_x, s->check))
		{
			ray->horz_x = s->next_x;
			ray->horz_y = s->next_y;
			ray->horz_dist = distance(s->next_x, s->next_y,
					s->px, s->py);
			return (1);
		}
		s->next_x += s->x_step;
		s->next_y += s->y_step;
	}
	return (0);
}

void	check_horizontal(t_game *game, t_ray *ray)
{
	t_ray_step	step;

	init_horizontal_intercept(game, ray, &step);
	init_horizontal_steps(ray, &step);
	horizontal_wall_hit(game, ray, &step);
}
