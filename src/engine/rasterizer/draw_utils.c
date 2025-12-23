/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:59:47 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/20 01:15:56 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

void    draw_ceiling_floor(t_game *game)
{
    int     x;
    int     y;

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



