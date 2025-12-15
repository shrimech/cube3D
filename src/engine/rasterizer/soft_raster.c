/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:18:19 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 22:30:27 by elhaiba hamza    ###   ########.fr       */
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
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x8B4513, game);
			else if (map[y][x] == '0')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xFFFFE0, game);
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x00FF00, game);
			else if (map[y][x] == ' ')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x000000, game);
			x++;
		}
		y++;
	}
}

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 15);
	map[0] = "        1111111111111111111111111";
	map[1] = "        1000000000110000000000001";
	map[2] = "        1011000001110000000000001";
	map[3] = "        1001000000000000000000001";
	map[4] = "111111111011000001110000000000001";
	map[5] = "100000000011000001110111111111111";
	map[6] = "11110111111111011100000010001    ";
	map[7] = "11110111111111011101010010001    ";
	map[8] = "11000000110101011100000010001    ";
	map[9] = "10000000000000001100000010001    ";
	map[10] = "10000000000000001101010010001    ";
	map[11] = "11000001110101011111011110N0111  ";
	map[12] = "11110111 1110101 101111010001    ";
	map[13] = "11111111 1111111 111111111111    ";
	map[14] = NULL;
	return (map);
}

int	draw_loop(t_game *game)
{
	t_camera	*camera;
	static int	frame_count = 0;

	camera = &game->camera;
	apply_motion(camera);
	/* clear_image(game); */
	draw_map(game);
	draw_square(camera->pos_x - 5, camera->pos_y - 5, 10, 0xFF0000, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (frame_count % 120 == 0)
	{
		printf("Frame %d: Player at (%.1f, %.1f), angle: %.2f\n", frame_count,
			camera->pos_x, camera->pos_y, camera->view_angle);
	}
	frame_count++;
	return (0);
}
