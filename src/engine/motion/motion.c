/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:10:30 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 04:10:30 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	calibrate_optics(t_camera *cam)
{
	cam->pos_x = WIDTH / 2;
	cam->pos_y = HEIGHT / 2;
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

int	move_camera()
{

}
