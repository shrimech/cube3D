/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:32:10 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 02:51:14 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "freefire");
	game->img = mlx_new_image(game->mlx, 720, 720);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->line_lengh,
			&game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
