/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:01 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 01:21:27 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"

void 	overwrite_spaces(t_map *map,int map_line)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i<map->height)
    {
        j = 0;
        map->map[i][map->width] = '\0';
        while(j<map->width)
        {
            if(map->hole_map[map_line][j] == '\n' || map->hole_map[map_line][j] == '\0')
                break;
            map->map[i][j] = map->hole_map[map_line][j];
            j++;
        }
        i++;
        map_line++;
    }
}