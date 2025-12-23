/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:10:30 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 19:57:03 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <stdio.h>
#include <stdlib.h>

void	calibrate_optics(t_camera *cam)
{
	if (cam->player == E_EAST)
		cam->view_angle = 0;
	else if (cam->player == E_SOUTH)
		cam->view_angle = PI / 2;
	else if (cam->player == E_WEST)
		cam->view_angle = PI;
	else if (cam->player == E_NORTH)
		cam->view_angle = 3 * PI / 2;
	cam->pos_x = cam->pos_x * BLOCK + BLOCK / 2.0;
	cam->pos_y = cam->pos_y * BLOCK + BLOCK / 2.0;
}

int	assert_motion(int keycode, t_camera *cam)
{
	if (keycode == KEY_ESC)
	{
		printf("ESC key pressed - exiting...\n");
		cleanup_exit(0, "");
	}
	if (keycode == KEY_W)
		cam->move_fwd = true;
	if (keycode == KEY_S)
		cam->move_back = true;
	if (keycode == KEY_A)
		cam->truck_left = true;
	if (keycode == KEY_D)
		cam->truck_right = true;
	if (keycode == KEY_LEFT)
		cam->rotate_left = true;
	if (keycode == KEY_RIGHT)
		cam->rotate_right = true;
	return (0);
}

int	stop_motion(int keycode, t_camera *cam)
{
	if (keycode == KEY_W)
		cam->move_fwd = false;
	if (keycode == KEY_S)
		cam->move_back = false;
	if (keycode == KEY_A)
		cam->truck_left = false;
	if (keycode == KEY_D)
		cam->truck_right = false;
	if (keycode == KEY_LEFT)
		cam->rotate_left = false;
	if (keycode == KEY_RIGHT)
		cam->rotate_right = false;
	return (0);
}

int	is_valid_move(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (0);
	map_x = (int)x;
	map_y = (int)y;
	if (game->map[map_y / BLOCK][map_x / BLOCK] == '1')
		return (0);
	return (1);
}
// NOTE: 25 line
void	apply_motion(t_game *game, t_camera *cam)
{
	double	move_step;
	double	cos_angle;
	double	sin_angle;
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (cam->rotate_left)
		cam->view_angle -= ROT_SPEED;
	if (cam->rotate_right)
		cam->view_angle += ROT_SPEED;
	if (cam->view_angle < 0)
		cam->view_angle += 2 * PI;
	if (cam->view_angle > 2 * PI)
		cam->view_angle -= 2 * PI;
	move_step = MOVE_SPEED;
	cos_angle = cos(cam->view_angle);
	sin_angle = sin(cam->view_angle);
	if (cam->move_fwd)
	{
		new_x += cos_angle * move_step;
		new_y += sin_angle * move_step;
	}
	if (cam->move_back)
	{
		new_x -= cos_angle * move_step;
		new_y -= sin_angle * move_step;
	}
	if (cam->truck_left)
	{
		new_x += sin_angle * move_step;
		new_y -= cos_angle * move_step;
	}
	if (cam->truck_right)
	{
		new_x -= sin_angle * move_step;
		new_y += cos_angle * move_step;
	}
	if (is_valid_move(game, cam->pos_x + new_x, cam->pos_y))
		cam->pos_x += new_x;
	if (is_valid_move(game, cam->pos_x, cam->pos_y + new_y))
		cam->pos_y += new_y;
}
