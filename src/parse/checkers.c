/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:33:06 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/26 11:18:01 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"
#include "libft.h"

bool	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

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
			cleanup_exit(1, ERR_MAP_OPEN);
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
			cleanup_exit(1, ERR_MAP_OPEN);
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
			if (map->map[i][j] == E_EMPTY || is_player(map->map[i][j]))
			{
				if (check_for_an_space(map, i, j))
				{
					cleanup_exit(1, ERR_MAP_OPEN);
				}
			}
			j++;
		}
		i++;
	}
}
