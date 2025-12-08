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

static int	mask = 0;

bool	is_map_line(char c)
{
	return (c == '0' || c == '1');
}

bool	is_empty_line(char c)
{
	return (c == '\n' || c == '\0');
}

int	check_element(char *first_element)
{
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
	if (mask == E_ALL)
		return (E_ALL);
	return (bit); // return the bit that was set
}

// void	fill_map_element(t_map *map, char *line, int element)
// {
// 	if (element == E_NO)
// 		map->no = extract_path(line);
// 	else if (element == E_SO)
// 		map->so = extract_path(line);
// 	else if (element == E_WE)
// 		map->we = extract_path(line);
// 	else if (element == E_EA)
// 		map->ea = extract_path(line);
// 	else if (element == E_F)
// 		map->f = extract_color(line);
// 	else if (element == E_C)
// 		map->c = extract_color(line);
// }

// int	parse_elements(t_map *map)
// {
// 	int	i;
// 	int	ret;
//
// 	i = 0;
// 	while (map->hole_map[i])
// 	{
// 		if (is_map_line(map->hole_map[i][0]))
// 		{
// 			if (mask != E_ALL)
// 				return (printf("Map reached before all elements loaded"));
// 			return (i);
// 		}
// 		if (is_empty_line(map->hole_map[i][0]))
// 		{
// 			i++;
// 			continue ;
// 		}
// 		ret = check_element(map->hole_map[i]);
// 		if (ret == -1)
// 		{
// 			write(2, "Duplicate elements\n", 20); // NOTE: here change with the exit function
// 			return (-1);
// 		}
// 		else if (ret == 0)
// 		{
// 			write(2, "Unknown line before map\n", 25); // NOTE: here change with the exit function
// 			return (-1);
// 		}
// 		fill_map_element(map, map->hole_map[i], ret);
// 	}
// 	return (i);
// }

// void	parse_map(void)
// {
//
// }

void	parse_hole_map(t_map *map)
{
	// Fill the textures and colors
    map->no = ft_strdup("./path_to_the_north_texture");
    map->so = ft_strdup("./path_to_the_south_texture");
    map->we = ft_strdup("./path_to_the_west_texture");
    map->ea = ft_strdup("./path_to_the_east_texture");
    map->f  = ft_strdup("220,100,0");
    map->c  = ft_strdup("225,30,0");

    // Allocate memory for map (14 lines)
    map->map = malloc(sizeof(char *) * 15); // 14 lines + NULL
    if (!map->map)
        return;

    map->map[0]  = ft_strdup("        1111111111111111111111111");
    map->map[1]  = ft_strdup("        1000000000110000000000001");
    map->map[2]  = ft_strdup("        1011000001110000000000001");
    map->map[3]  = ft_strdup("        1001000000000000000000001");
    map->map[4]  = ft_strdup("111111111011000001110000000000001");
    map->map[5]  = ft_strdup("100000000011000001110111111111111");
    map->map[6]  = ft_strdup("11110111111111011100000010001");
    map->map[7]  = ft_strdup("11110111111111011101010010001");
    map->map[8]  = ft_strdup("11000000110101011100000010001");
    map->map[9]  = ft_strdup("10000000000000001100000010001");
    map->map[10] = ft_strdup("10000000000000001101010010001");
    map->map[11] = ft_strdup("11000001110101011111011110N0111");
    map->map[12] = ft_strdup("11110111 1110101 101111010001");
    map->map[13] = ft_strdup("11111111 1111111 111111111111");
    map->map[14] = NULL; // Null-terminate

    // Optional width/height
    map->height = 14;
    map->width = strlen(map->map[4]);
}
