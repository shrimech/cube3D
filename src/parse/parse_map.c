/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:34:27 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/21 22:34:06 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <freefire.h>

void	*ft_salloc(size_t nmemb, size_t size)
{
	void	*res;

	res = my_alloc(nmemb * size, SCOPE_GAME);
	ft_memset(res, ' ', nmemb * size);
	return (res);
}

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
			return (cleanup_exit(1, ERR_INV_TILE), false);
		}
		i++;
	}
	if (i == 0)
		return (cleanup_exit(1, ERR_INV_MAP_LINE), false);
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
		cleanup_exit(1, ERR_MAP_MISSING);
	while (mapline < map->height)
	{
		if (!is_valid_mapline(map->file_buffer[mapline]))
			cleanup_exit(1, ERR_INV_MAP_LINE);
		len = ft_strlen(map->file_buffer[mapline]);
		if (map->file_buffer[mapline][len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		mapline++;
	}
	map->width = width;
	map->height = map->height - first_line;
}
