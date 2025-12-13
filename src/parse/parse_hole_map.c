/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:37 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/09 18:41:25 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <freefire.h>
#include <stdio.h>

static int	mask = 0;

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
		return (0); // line is not an element
	if (mask & bit)
		return (-1); // duplicate detected
	mask |= bit;     // set the bit
	return (bit);    // return the bit that was set
}

void	fill_map_element(t_map *map, char *line, int element)
{
	int	*tmp;

	tmp = NULL;
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
		tmp = extract_color(extract_path(line));
		ft_memcpy(map->f, tmp, sizeof(int) * 3);
	}
	else if (element == E_C)
	{
		tmp = extract_color(extract_path(line));
		ft_memcpy(map->c, tmp, sizeof(int) * 3);
	}
}

int	parse_elements(t_map *map)
{
	int	i;
	int	ret;

	i = 0;
	while (i < map->height)
	{
		if (is_map_line(map->hole_map[i][0]))
		{
			if (mask != E_ALL)
				return (printf("Map reached before all elements loaded"));
			return (i);
		}
		if (is_empty_line(map->hole_map[i][0]))
		{
			i++;
			continue ;
		}
		ret = check_element(map->hole_map[i]);
		if (ret == -1)
		{
			write(2, "Duplicate elements\n", 20);
			// NOTE: here change with the exit function
			return (-1);
		}
		else if (ret == 0)
		{
			write(2, "Unknown line before map\n", 25);
			// NOTE: here change with the exit function
			return (-1);
		}
		fill_map_element(map, map->hole_map[i], ret);
		i++;
	}
	return (i);
}

void	parse_map(t_map *map, int map_line)
{
	(void)map;
	(void)map_line;
}

void	parse_hole_map(t_map *map)
{
	int	map_line;

	map_line = parse_elements(map);
	parse_map(map, map_line);
	map_width(map, map_line);
}
