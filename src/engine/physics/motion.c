/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:10:30 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 21:58:39 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

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

void	apply_motion(t_game *game, t_camera *cam)
{
	double	dx;
	double	dy;

	update_rotation(cam);
	compute_motion(cam, &dx, &dy);
	apply_translation(game, cam, dx, dy);
}
