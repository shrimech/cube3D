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

#include "game.h"
#include <math.h>

/* Draw a line from (x0, y0) to (x1, y1) using Bresenham's algorithm. */
void draw_line(int x0, int y0, int x1, int y1, int color, t_game *game)
{
    int delta_x = abs(x1 - x0);
    int step_x;
    if (x0 < x1)
        step_x = 1;
    else
        step_x = -1;
    int delta_y = -abs(y1 - y0);
    int step_y;
    if (y0 < y1)
        step_y = 1;
    else
        step_y = -1;
    int error = delta_x + delta_y;
    int finished = 0;

    while (!finished)
    {
        put_pixel(x0, y0, color, game);
        if (x0 == x1 && y0 == y1)
            finished = 1;
        else
        {
            int error2 = 2 * error;
            if (error2 >= delta_y)
            {
                error += delta_y;
                x0 += step_x;
            }
            if (error2 <= delta_x)
            {
                error += delta_x;
                y0 += step_y;
            }
        }
    }
}
