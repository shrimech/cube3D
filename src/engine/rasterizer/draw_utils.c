/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:59:47 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/23 21:46:55 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

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

void	draw_ceiling_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(x, y, game->map_data->c, game);
			else
				put_pixel(x, y, game->map_data->f, game);
			x++;
		}
		y++;
	}
}

void	draw_text_y(t_game *game, t_wall wall, t_tex_info info, t_texture tex)
{
	double			tex_y;
	int				y;
	unsigned int	color;

	y = wall.wall_start;
	while (y <= wall.wall_end)
	{
		tex_y = fmod(info.tex_pos, (double)(game->images[tex].height - 1));
		info.tex_pos += info.step;
		color = get_tex_color(game->images[tex], info.tex_x, (int)tex_y);
		put_pixel(wall.x, y, color, game);
		y++;
	}
}

void	render_wall(t_game *game, t_wall wall, t_ray ray)
{
	t_tex_info	info;
	t_texture	tex;

	tex = which_tex(ray);
	info = info_tex(game, wall, ray, tex);
	draw_text_y(game, wall, info, tex);
}
