/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:10:30 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 07:01:58 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <stdio.h>
#include <stdlib.h>

void	calibrate_optics(t_camera *cam)
{
	cam->view_angle = PI / 2;
	cam->move_fwd = false;
	cam->move_back = false;
	cam->truck_left = false;
	cam->truck_right = false;
	cam->rotate_left = false;
	cam->rotate_right = false;
}

int	assert_motion(int keycode, t_camera *cam)
{
	if (keycode == KEY_ESC)
	{
		printf("ESC key pressed - exiting...\n");
		exit(0);
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
    int map_x;
    int map_y;
    if (x < 0 || y < 0)
        return (0);
    map_x = (int)x;
    map_y = (int)y;
    if (game->map[map_y / BLOCK][map_x / BLOCK] == '1')
        return (0);
    return (1);
}

void	apply_motion(t_game *game, t_camera *cam)
{
	float	move_step;
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;

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
	if (is_valid_move(game, cam->pos_x + new_x,cam->pos_y))
       cam->pos_x += new_x;
    if (is_valid_move(game,cam->pos_x,cam->pos_y + new_y))
       cam->pos_y += new_y;
}

