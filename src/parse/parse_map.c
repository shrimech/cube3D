/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:34:27 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/13 00:34:54 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "types.h"
#include <freefire.h>
#include <stdio.h>




void	map_width(t_map *map, int mapline)
{
	int	width;
	int	len;
	int first_line;

	width = 0;
	first_line = mapline;
	while (mapline < map->height)
	{
		if (!is_map_line(map->hole_map[mapline][0]))
		{
			printf("MAP ERROR\n");
			return;
		}
		len = ft_strlen(map->hole_map[mapline]);
		if (map->hole_map[mapline][len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		mapline++;
	}
	map->width = width;
	map->height = map->height - first_line;
}
