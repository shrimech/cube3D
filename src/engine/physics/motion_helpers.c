/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:52:52 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/23 21:55:30 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

void	update_rotation(t_camera *cam)
{
	if (cam->rotate_left)
		cam->view_angle -= ROT_SPEED;
	if (cam->rotate_right)
		cam->view_angle += ROT_SPEED;
	if (cam->view_angle < 0)
		cam->view_angle += 2 * PI;
	if (cam->view_angle > 2 * PI)
		cam->view_angle -= 2 * PI;
}

void	compute_motion(t_camera *cam, double *dx, double *dy)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(cam->view_angle);
	sin_angle = sin(cam->view_angle);
	if (cam->move_fwd)
	{
		*dx += cos_angle * MOVE_SPEED;
		*dy += sin_angle * MOVE_SPEED;
	}
	if (cam->move_back)
	{
		*dx -= cos_angle * MOVE_SPEED;
		*dy -= sin_angle * MOVE_SPEED;
	}
	if (cam->truck_left)
	{
		*dx += sin_angle * MOVE_SPEED;
		*dy -= cos_angle * MOVE_SPEED;
	}
	if (cam->truck_right)
	{
		*dx -= sin_angle * MOVE_SPEED;
		*dy += cos_angle * MOVE_SPEED;
	}
}

void	apply_translation(t_game *game, t_camera *cam, double dx, double dy)
{
	if (is_valid_move(game, cam->pos_x + dx, cam->pos_y))
		cam->pos_x += dx;
	if (is_valid_move(game, cam->pos_x, cam->pos_y + dy))
		cam->pos_y += dy;
}
