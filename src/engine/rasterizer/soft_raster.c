/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 04:18:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 20:00:59 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

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



int	draw_loop(t_game *game)
{
	apply_motion(game, game->camera);
	clear_image(game);
	draw_ceiling_floor(game);

	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

	return (0);
}






















































/* 	static int	frame_count = 0; */



// if (frame_count % 120 == 0)
// {
// 	printf("Frame %d: player at (%.1f, %.1f), angle: %.2f\n", frame_count,
// 		game->camera->pos_x, game->camera->pos_y, game->camera->view_angle);
// }
// frame_count++;



// void	draw_map(t_game *game)
// {
// 	char	**map;
// 	int		y;
// 	int		x;
//
// 	map = game->map;
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '1')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x234C6A, game);
// 			else if (map[y][x] == '0')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
// 			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
// 				|| map[y][x] == 'W')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xE3E3E3, game);
// 			else if (map[y][x] == ' ')
// 				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x222222, game);
// 			x++;
// 		}
// 		y++;
// 	}
// }



// void	draw_square(int x, int y, int size, int color, t_game *game)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			put_pixel(x + j, y + i, color, game);
// 			j++;
// 		}
// 		i++;
// 	}
// }
//

