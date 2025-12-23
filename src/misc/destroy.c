/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:01:40 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 22:14:57 by shrimech         ###   ########.fr       */
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
	if (!game)
		return ;
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
