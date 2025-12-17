/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:18:19 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/15 15:59:41 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <freefire.h>
#include <minilibx-linux/mlx.h>

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->line_lengh + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + j, y + i, color, game);
			j++;
		}
		i++;
	}
}

#include <math.h>

// DDA Algorithm implementation
void draw_line(t_camera *cam, t_game *game, float angle, int x)
{
    // 1. Calculate Ray Direction
    float ray_dir_x = cos(angle);
    float ray_dir_y = sin(angle);
    // 2. Current Map Box (Integer coordinates)
    int map_x = (int)(cam->pos_x / BLOCK);
    int map_y = (int)(cam->pos_y / BLOCK);

    // 3. Length of ray from one x or y-side to next x or y-side
    // (We use fabs to handle negative directions)
    float delta_dist_x = fabs(1 / ray_dir_x);
    float delta_dist_y = fabs(1 / ray_dir_y);

    // 4. Variables for stepping and initial side distance
    int step_x;
    int step_y;
    float side_dist_x;
    float side_dist_y;

    // Calculate step and initial sideDist based on ray direction
    // Note: We divide cam coordinates by BLOCK to work in "grid units"
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = ((cam->pos_x / BLOCK) - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - (cam->pos_x / BLOCK)) * delta_dist_x;
    }
    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = ((cam->pos_y / BLOCK) - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - (cam->pos_y / BLOCK)) * delta_dist_y;
    }
    // 5. DDA Loop: Jump to next map square until we hit a wall
    int hit = 0;
    int side; // 0 for NS, 1 for EW (used for shading)

    while (hit == 0)
    {
        // Jump to whichever side is closer
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        // Check for wall hit
        if (game->map[map_y][map_x] == '1')
            hit = 1;
    }
    // 6. Calculate Distance and Fisheye Correction
    float perp_wall_dist;
    // Calculate distance projected on camera direction
    // (side_dist - delta_dist) is the Euclidean distance in "grid units"
    if (side == 0)
        perp_wall_dist = (side_dist_x - delta_dist_x);
    else
        perp_wall_dist = (side_dist_y - delta_dist_y);
    // Convert grid distance back to pixel distance
    float distance = perp_wall_dist * BLOCK;
    // Fix Fisheye effect
    distance *= cos(angle - cam->view_angle);
    // 7. Calculate Wall Height and Draw
    float height = (BLOCK / distance) * (WIDTH / 2);
    int start_y = (HEIGHT - height) / 2;
    if (start_y < 0) start_y = 0;
    int end_y = start_y + height;
    if (end_y >= HEIGHT) end_y = HEIGHT - 1;
    // Choose color (darker for y-sides for pseudo-3D effect)
    int color = (side == 1) ? 0xDDDDDD : 0xFFFFFF; // Grey vs White
    // Or use your original fixed blue: int color = 255; 
    // Draw the vertical stripe
    while (start_y < end_y)
    {
        put_pixel(x, start_y, color, game);
        start_y++;
    }
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x234C6A, game);
			else if (map[y][x] == '0')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
			else if (map[y][x] == ' ')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x222222, game);
			x++;
		}
		y++;
	}
}

int draw_loop(t_game *game)
{
    t_camera *camera = &game->camera;

    apply_motion(camera);

    clear_image(game);

    float   ray_angle;
    int     x;

    x = 0;
    while (x < WIDTH)
    {
        float fov_step = (float)x / (float)WIDTH; 
        ray_angle = camera->view_angle - (FOV / 2) + (fov_step * FOV);

        draw_line(camera, game, ray_angle, x);

        x++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

    return (0);
}

// int	draw_loop(t_game *game)
// {
// 	t_camera	*camera;
// 	static int	frame_count = 0;
//
// 	camera = &game->camera;
// 	apply_motion(camera);
// 	clear_image(game);
// 	draw_map(game);
// 	draw_square(camera->pos_x - 5, camera->pos_y - 5, 10, 0xFF0000, game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	if (frame_count % 120 == 0)
// 	{
// 		printf("Frame %d: player at (%.1f, %.1f), angle: %.2f\n", frame_count,
// 			camera->pos_x, camera->pos_y, camera->view_angle);
// 	}
// 	frame_count++;
// 	return (0);
// }
