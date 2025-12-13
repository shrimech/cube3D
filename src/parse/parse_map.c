/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:34:27 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/13 14:18:31 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "types.h"
#include <freefire.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_valid_mapline(char *mapline)
{
	int	i;

	i = 0;
	while (mapline[i] && mapline[i] != '\n')
	{
		if (!(mapline[i] == E_WALL || mapline[i] == E_EMPTY
				|| mapline[i] == E_EAST || mapline[i] == E_SOUTH
				|| mapline[i] == E_WEST || mapline[i] == E_NORTH
				|| mapline[i] == E_SPACE))
		{
			return (set_error(ERR_INV_TILE), false);
		}
		i++;
	}
	if (i == 0)
		return (set_error(ERR_INV_MAP_LINE), false);
	return (true);
}

void	map_width(t_map *map, int mapline)
{
	int	width;
	int	len;
	int	first_line;

	width = 0;
	first_line = mapline;
	if (first_line >= map->height)
	{
		set_error(ERR_MAP_MISSING);
		ft_exit(map);
	}
	while (mapline < map->height)
	{
		if (!is_valid_mapline(map->hole_map[mapline]))
			ft_exit(map);
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
