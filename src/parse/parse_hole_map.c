/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hole_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:37 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/21 23:11:23 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <freefire.h>

static int	g_mask = 0;

int	check_element(char *first_element)
{
	int	bit;

	bit = 0;
	if (strncmp(first_element, NO, 3) == 0)
		bit = E_NO;
	else if (strncmp(first_element, SO, 3) == 0)
		bit = E_SO;
	else if (strncmp(first_element, WE, 3) == 0)
		bit = E_WE;
	else if (strncmp(first_element, EA, 3) == 0)
		bit = E_EA;
	else if (strncmp(first_element, F, 2) == 0)
		bit = E_F;
	else if (strncmp(first_element, C, 2) == 0)
		bit = E_C;
	else
		return (0);
	if (g_mask & bit)
		return (-1);
	g_mask |= bit;
	return (bit);
}

int	parse_elements(t_map *map)
{
	int	i;
	int	ret;

	i = 0;
	while (i < map->height)
	{
		if (is_map_line(map->file_buffer[i][0]))
		{
			if (g_mask != E_ALL)
				return (cleanup_exit(1, ERR_MAP_EARLY), -1);
			return (i);
		}
		if (is_empty_line(map->file_buffer[i][0]))
		{
			i++;
			continue ;
		}
		ret = check_element(map->file_buffer[i]);
		if (ret == -1)
			cleanup_exit(1, ERR_DUP_ELEMENTS);
		else if (ret == 0)
			cleanup_exit(1, ERR_INV_ELEMENT);
		fill_map_element(map, map->file_buffer[i++], ret);
	}
	return (i);
}

void	player_position(t_map *map, t_game *game)
{
	int		i;
	int		j;
	bool	one_p;

	one_p = false;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_player(map->map[i][j]) && !one_p)
			{
				game->camera->pos_x = j;
				game->camera->pos_y = i;
				game->camera->player = map->map[i][j];
				one_p = !one_p;
			}
			else if (is_player(map->map[i][j]) && one_p)
				cleanup_exit(1, ERR_MANY_PLAYERS);
			j++;
		}
		i++;
	}
	if (!one_p)
		cleanup_exit(1, ERR_NO_PLAYER);
}

void	parse_map(t_map *map, int map_line)
{
	int	i;

	i = 0;
	map->map = malloc((map->height + 1) * 8);
	while (i < map->height)
		map->map[i++] = ft_salloc(1, map->width + 1);
	overwrite_spaces(map, map_line);
	map->map[map->height] = NULL;
}

void	parse_hole_map(t_map *map, t_game *game)
{
	int	map_line;

	map_line = parse_elements(map);
	map_width(map, map_line);
	parse_map(map, map_line);
	player_position(map, game);
	map_border(map);
}
