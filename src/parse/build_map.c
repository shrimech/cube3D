/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:01 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/21 23:08:19 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"

void	overwrite_spaces(t_map *map, int map_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		map->map[i][map->width] = '\0';
		while (j < map->width)
		{
			if (map->file_buffer[map_line][j] == '\n'
				|| map->file_buffer[map_line][j] == '\0')
				break ;
			map->map[i][j] = map->file_buffer[map_line][j];
			j++;
		}
		i++;
		map_line++;
	}
}

void	fill_map_element(t_map *map, char *line, int element)
{
	if (element == E_NO)
		map->no = extract_path(line);
	else if (element == E_SO)
		map->so = extract_path(line);
	else if (element == E_WE)
		map->we = extract_path(line);
	else if (element == E_EA)
		map->ea = extract_path(line);
	else if (element == E_F)
	{
		map->f = extract_color(extract_path(line));
	}
	else if (element == E_C)
	{
		map->c = extract_color(extract_path(line));
	}
}
