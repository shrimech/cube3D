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

#include "types.h"
#include <freefire.h>

bool	is_tile(char c)
{
	return (c == '\0' || c == '\n' || c == E_SPACE);
}

int	check_element(char *first_element)
{
	static int	mask = 0;
	int			bit;

	bit = 0;
	if (strncmp(first_element, "NO ", 3) == 0)
		bit = E_NO;
	else if (strncmp(first_element, "SO ", 3) == 0)
		bit = E_SO;
	else if (strncmp(first_element, "WE ", 3) == 0)
		bit = E_WE;
	else if (strncmp(first_element, "EA ", 3) == 0)
		bit = E_EA;
	else if (strncmp(first_element, "F ", 2) == 0)
		bit = E_F;
	else if (strncmp(first_element, "C ", 2) == 0)
		bit = E_C;
	else
		return (0); // line is not an element
	if (mask & bit)
		return (-1); // duplicate detected
	mask |= bit;     // set the bit
	return (bit);    // return the bit that was set
}

/*
 *in this function i want to split every line of the map->hole_map (char **)
 *except for lines that have just "\n".
 *and if the check check_element() return error stop
 *if not stop till u find '0' or '1'
 * */

fill_map_element(t_map *map, char *line, int element)
{
}

int	parse_elements(t_map *map)
{
	int	i;
	int	ret;

	i = 0;
	while (map->hole_map[i])
	{
		if (is_tile(map->hole_map[i][0]) == false)
		{
			i++;
			continue ;
		}
		ret = check_element(map->hole_map[i]);
		if (ret == -1)
		{
			write(2, "Duplicates\n", 25);
				// NOTE: here change with the exit function
			return (-1);
		}
		else if (ret == 0)
		{
			write(2, "Unknown line before map\n", 30);
				// NOTE: here change with the exit function
			return (-1);                               // stop parsing, error
		}
		fill_map_element(map, map->hole_map[i], ret);
		i++;
	}
	return (i);
}

void	parse_map(void)
{
}

void	parse_hole_map(t_map *map)
{
}
