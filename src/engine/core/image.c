/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 05:12:56 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/22 08:38:40 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"
#include "game.h"
#include "minilibx-linux/mlx.h"

// NOTE: handli

static void	open_images(t_game *game)
{
	game->images[0].img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->map_data->no, &game->images[0].width,
			&game->images[0].height);
	game->images[1].img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->map_data->so, &game->images[1].width,
			&game->images[1].height);
	game->images[2].img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->map_data->we, &game->images[2].width,
			&game->images[2].height);
	game->images[3].img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->map_data->ea, &game->images[3].width,
			&game->images[3].height);
}

void	load_images(t_game *game)
{
	int	i;

	i = 0;
	open_images(game);
	while (i < 4)
	{
		game->images[i].data = mlx_get_data_addr(game->images[i].img_ptr,
				&game->images[i].bpp, &game->images[i].line_length,
				&game->images[i].endian);
		i++;
	}
}

t_texture	which_tex(t_ray ray)
{
	if (ray.was_vertical)
	{
		if (ray.is_facing_right)
		{
			return (T_WEST);
		}
		else
		{
			return (T_EAST);
		}
	}
	else
	{
		if (ray.is_facing_down)
		{
			return (T_NORTH);
		}
		else
		{
			return (T_SOUTH);
		}
	}
	return (-1);
}

t_tex_info	info_tex(t_game *game, t_wall wall, t_ray ray, t_texture tex)
{
	double		wall_hit_decimal;
	t_tex_info	info;
	int			wall_start;
	int			tex_width;

	tex_width = game->images[tex].width;
	if (ray.was_vertical)
		wall_hit_decimal = ray.wall_hit_y / BLOCK;
	else
		wall_hit_decimal = ray.wall_hit_x / BLOCK;
	wall_hit_decimal -= floor(wall_hit_decimal);
	info.tex_x = (int)(wall_hit_decimal * tex_width);
	if ((ray.was_vertical && !ray.is_facing_right) || (!ray.was_vertical
			&& ray.is_facing_down))
	{
		info.tex_x = tex_width - info.tex_x - 1;
	}
	info.step = 1.0 * game->images[tex].height / wall.wall_height;
	wall_start = (((double)HEIGHT / 2) - wall.wall_height / 2.0);
	if (wall_start < 0)
		wall_start = 0;
	info.tex_pos = (wall_start - (double)HEIGHT / 2 + wall.wall_height / 2.0)
		* info.step;
	return (info);
}

unsigned int	get_tex_color(t_image tex, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= tex.width)
		x = tex.width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex.height)
		y = tex.height - 1;
	pixel = tex.data + (y * tex.line_length + x * (tex.bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_text_y(t_game *game, t_wall wall, t_tex_info info, t_texture tex)
{
	double			tex_y;
	int				y;
	unsigned int	color;

	y = wall.wall_start;
	while (y < wall.wall_end)
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
