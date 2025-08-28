/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:37 by ehamza            #+#    #+#             */
/*   Updated: 2025/08/28 12:43:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"

static bool	is_valid_tile(char tile)
{
	return (tile == WALL || tile == EMPTY || tile == EAST || tile == WEST
		|| tile == NORTH || tile == SOUTH);
}

t_map	parse_map_grid(char **raw_chars, long max_with, long height)
{
	t_map	(map), (empty);
	int		(x), (y);
	char	tile;

	y = -1;
	empty = (t_map){0};
	map.height = height;
	map.width = max_with;
	map.grid = malloc(height * sizeof(t_point *));
	while (raw_chars[++y])
	{
		x = -1;
		map.grid[y] = malloc(max_with * sizeof(t_point));
		while (raw_chars[y][++x])
		{
			tile = raw_chars[y][x];
			if (is_valid_tile(tile))
				map.grid[y][x].tile = tile;
			else if (tile == ' ')
				map.grid[y][x].tile = NONE;
			else
				return (empty);
		}
	}
	return (map);
}
