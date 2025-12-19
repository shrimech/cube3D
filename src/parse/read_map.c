/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/19 16:49:52 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	map_init(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->map = NULL;
	map->hole_map = NULL;
	map->height = -1;
	map->width = -1;
}

static char	**realloc_map(char **old_map, size_t old_size, char *new_line)
{
	char	**new_map;
	size_t	i;

	i = 0;
	new_map = malloc(sizeof(char *) * (old_size + 1));
	if (!new_map)
		return (set_error(ERR_ALLOC), NULL);
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = new_line;
	free(old_map);
	return (new_map);
}

char	**read_map(t_map *map, int fd)
{
	char	**hole_map;
	char	*line;
	char	**tmp;
	int		count_lines;

	hole_map = NULL;
	count_lines = 0;
	line = get_next_line(fd);
	if (!line)
		return (set_error(ERR_GNL), ft_exit(map), NULL);
	while (line != NULL)
	{
		tmp = realloc_map(hole_map, count_lines, line);
		if (!tmp)
			return (set_error(ERR_ALLOC), NULL);
		hole_map = tmp;
		count_lines++;
		line = get_next_line(fd);
	}
	tmp = realloc_map(hole_map, count_lines, NULL);
	if (tmp)
		hole_map = tmp;
	map->height = count_lines;
	return (hole_map);
}
