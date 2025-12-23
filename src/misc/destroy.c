/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:01:40 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/22 16:13:59 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 4)
	{
		if (game->images[i].img_ptr && game->mlx)
		{
			mlx_destroy_image(game->mlx, game->images[i].img_ptr);
			game->images[i].img_ptr = NULL;
		}
		i++;
	}
}

void	destroy_game(t_game *game)
{
	(void)game;
	destroy_textures(game);
	if (game->img && game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
	if (game->win && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
