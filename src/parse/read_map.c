/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 22:55:51 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <freefire.h>
#include <stdlib.h>

t_map	*map_init(void)
{
	t_map	*map;

	map = my_alloc(sizeof(t_map), SCOPE_GAME);
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->map = NULL;
	map->file_buffer = NULL;
	map->c = -1;
	map->f = -1;
	map->height = -1;
	map->width = -1;
	return (map);
}

static char	**realloc_map(char **old_map, size_t old_size, char *new_line)
{
	char	**new_map;
	size_t	i;

	i = 0;
	new_map = my_alloc(sizeof(char *) * (old_size + 1), SCOPE_PARSE);
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = new_line;
	return (new_map);
}

char	**read_map(t_map *map, int fd)
{
	char	**whole_map;
	char	*line;
	char	**tmp;
	int		count_lines;

	whole_map = NULL;
	count_lines = 0;
	line = get_next_line(fd);
	if (!line)
		return (cleanup_exit(1, ERR_GNL), NULL);
	collector_register(line, SCOPE_PARSE);
	while (line != NULL)
	{
		tmp = realloc_map(whole_map, count_lines, line);
		whole_map = tmp;
		count_lines++;
		line = get_next_line(fd);
		collector_register(line, SCOPE_PARSE);
	}
	tmp = realloc_map(whole_map, count_lines, NULL);
	whole_map = tmp;
	map->height = count_lines;
	return (whole_map);
}
