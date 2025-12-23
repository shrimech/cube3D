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

/*
** Extracts a raw vertical column of pixels from the texture.
** @param img: The image structure containing data, width, height, etc.
** @param x: The x-coordinate of the column you want to fetch.
** @param buffer: A pointer to an int array where the colors will be stored.
** (Must be size of img->height).
*/
void	get_texture_column(t_image *img, int x, int *buffer)
{
	int				y;
	int				offset;
	char			*pixel_ptr;
	unsigned int	color;

	if (x < 0 || x >= img->width)
		return ;
	y = 0;
	while (y < img->height)
	{
		offset = (y * img->line_length) + (x * (img->bpp / 8));
		pixel_ptr = img->data + offset;
		color = *(unsigned int *)pixel_ptr;
		buffer[y] = color;
		y++;
	}
}
