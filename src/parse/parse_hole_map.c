/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hole_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:37 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/13 13:59:01 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "types.h"
#include <freefire.h>
#include <stdio.h>

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

void	fill_map_element(t_map *map, char *line, int element)
{
	if (element == E_NO)
		map->no = extract_path(map, line);
	else if (element == E_SO)
		map->so = extract_path(map, line);
	else if (element == E_WE)
		map->we = extract_path(map, line);
	else if (element == E_EA)
		map->ea = extract_path(map, line);
	else if (element == E_F)
	{
		map->f = extract_color(map, extract_path(map, line));
	}
	else if (element == E_C)
	{
		map->c = extract_color(map, extract_path(map, line));
	}
}

// NOTE: here change with the exit function

int	parse_elements(t_map *map)
{
	int	i;
	int	ret;

	i = 0;
	while (i < map->height)
	{
		if (is_map_line(map->hole_map[i][0]))
		{
			if (g_mask != E_ALL)
				return (set_error(ERR_MAP_EARLY), ft_exit(map), -1);
			return (i);
		}
		if (is_empty_line(map->hole_map[i][0]))
		{
			i++;
			continue ;
		}
		ret = check_element(map->hole_map[i]);
		if (ret == -1)
			return (set_error(ERR_DUP_ELEMENTS), ft_exit(map), -1);
		else if (ret == 0)
			return (set_error(ERR_INV_ELEMENT), ft_exit(map), -1);
		fill_map_element(map, map->hole_map[i++], ret);
	}
	return (i);
}

void	parse_hole_map(t_map *map)
{
	int	map_line;

	map_line = parse_elements(map);
	print_error();
	map_width(map, map_line);
	parse_map(map, map_line);
}
