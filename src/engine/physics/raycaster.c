/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:56:43 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/20 19:15:54 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>
#include <stdlib.h>

#define MAX_RAY_DIST 10000.0
#define RAY_STEP 1.0

static double clamp_double(double v, double lo, double hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

static int is_wall_at(t_game *game, double px, double py)
{
    int map_x;
    int map_y;

    if (px < 0 || py < 0)
        return 1;
    map_x = (int)(px) / BLOCK;
    map_y = (int)(py) / BLOCK;
    if (!game->map || !game->map[0])
        return 1;
    if (map_y < 0)
        return 1;
    int map_height = 0;
    while (game->map[map_height])
        map_height++;
    if (map_y >= map_height)
        return 1;
    int row_len = 0;
    while (game->map[map_y][row_len])
        row_len++;
    if (map_x < 0 || map_x >= row_len)
        return 1;
    return (game->map[map_y][map_x] == '1');
}

static void draw_vertical_line(t_game *game, int x, int y0, int y1, int color)
{
    if (x < 0 || x >= WIDTH)
        return;
    if (y0 < 0)
        y0 = 0;
    if (y1 > HEIGHT)
        y1 = HEIGHT;
    int y = y0;
    while (y < y1)
    {
        put_pixel(x, y, color, game);
        y++;
    }
}

static int shade_from_distance(double dist)
{
    double d = clamp_double(dist / 200.0, 0.0, 1.0);
    int shade = (int)((1.0 - d) * 255.0);
    if (shade < 0)
        shade = 0;
    if (shade > 255)
        shade = 255;
    return (shade << 16) | (shade << 8) | shade;
}

void render_scene(t_game *game)
{
    t_camera *cam = &game->camera;
    double half_fov = FOV / 2.0;
    int col = 0;
    while (col < WIDTH)
    {
        double camera_ratio = (double)col / (double)WIDTH;
        double ray_angle = cam->view_angle - half_fov + camera_ratio * FOV;
        while (ray_angle < 0)
            ray_angle += 2 * PI;
        while (ray_angle >= 2 * PI)
            ray_angle -= 2 * PI;
        double ray_dx = cos(ray_angle);
        double ray_dy = sin(ray_angle);
        double cur_x = cam->pos_x;
        double cur_y = cam->pos_y;
        double dist = 0.0;
        int hit = 0;
        while (!hit && dist < MAX_RAY_DIST)
        {
            cur_x += ray_dx * RAY_STEP;
            cur_y += ray_dy * RAY_STEP;
            dist += RAY_STEP;
            if (is_wall_at(game, cur_x, cur_y))
                hit = 1;
        }
        if (!hit)
        {
            col++;
            continue;
        }
        double delta = ray_angle - cam->view_angle;
        if (delta > PI)
            delta -= 2 * PI;
        if (delta < -PI)
            delta += 2 * PI;
        double corrected_dist = dist * cos(delta);
        if (corrected_dist <= 0.0001)
            corrected_dist = 0.0001;
        int projected_height = (int)((BLOCK * (double)HEIGHT) / corrected_dist);
        int slice_top = (HEIGHT / 2) - (projected_height / 2);
        int slice_bottom = slice_top + projected_height;
        int color = shade_from_distance(corrected_dist);
        draw_vertical_line(game, col, slice_top, slice_bottom, color);
        col++;
    }
}
