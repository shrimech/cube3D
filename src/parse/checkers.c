/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:33:06 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/19 16:38:22 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

bool	is_player(char c)
{
	return (c == E_EAST || c == E_SOUTH || c == E_NORTH || c == E_WEST);
}

void	check_start_end(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (!is_map_line(map->map[i][0]) || !is_map_line(map->map[i][map->width
				- 1]) || map->map[i][map->width - 1] == E_EMPTY
			|| map->map[i][0] == E_EMPTY)
		{
			write(2, "ERROR: 0 in vertic of line\n", 27);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (!is_map_line(map->map[0][i]) || !is_map_line(map->map[map->height
				- 1][i]) || map->map[0][i] == E_EMPTY || map->map[map->height
			- 1][i] == E_EMPTY)
		{
			write(2, "ERROR: 0 in horizont of line\n", 29);
			exit(1);
		}
		i++;
	}
}

bool	check_for_an_space(t_map *map, int i, int j)
{
	return (map->map[i + 1][j] == E_SPACE || map->map[i - 1][j] == E_SPACE
		|| map->map[i][j + 1] == E_SPACE || map->map[i][j - 1] == E_SPACE
		|| map->map[i + 1][j + 1] == E_SPACE || map->map[i - 1][j
		+ 1] == E_SPACE || map->map[i + 1][j - 1] == E_SPACE || map->map[i
		- 1][j + 1] == E_SPACE);
}

void	map_border(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	check_start_end(map);
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == E_EMPTY)
			{
				if (check_for_an_space(map, i, j))
				{
					write(2, "Error: an space collective with an empty\n", 41);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
