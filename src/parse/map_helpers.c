/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:48 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/19 16:47:21 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

bool	is_map_line(char c)
{
	return (c == E_WALL || c == E_EMPTY || c == E_SPACE);
}

bool	is_empty_line(char c)
{
	return (c == '\n' || c == '\0');
}

char	*extract_path(t_map *map, char *line)
{
	char	**elements;
	char	*path;
	int		count;

	count = 0;
	elements = ft_split(line, ' ');
	if (!elements)
		return (set_error(ERR_SPLIT), ft_exit(map), NULL);
	while (elements[count])
		count++;
	if (count != 2 || elements[1][0] == '\0')
	{
		set_error(ERR_TEXTURE_LINE);
		ft_exit(map);
		return (NULL);
	}
	path = ft_strdup(elements[1]);
	return (path);
}

int	takergb(char **rgb_str)
{
	int	i;
	int	value;
	int	rgb;

	i = 0;
	rgb = 0;
	while (i < 3)
	{
		value = ft_atoi(rgb_str[i]);
		if (value != (unsigned char)value)
		{
			write(2, "Error: RGB values are just one byte\n", 36);
			exit(1);
		}
		rgb |= (value << (16 - 8 * i));
		i++;
	}
	return (rgb);
}

int	extract_color(t_map *map, char *element)
{
	char	**rgb_str;
	int		rgb;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (element[i])
	{
		if (element[i] == ',')
			count++;
		i++;
	}
	i = 0;
	if (count != 2)
		return (set_error(ERR_SPLIT), ft_exit(map), -1);
	rgb_str = ft_split(element, ',');
	if (!rgb_str || !rgb_str[0] || !rgb_str[1] || !rgb_str[2]
		|| rgb_str[2][0] == '\n')
		return (set_error(ERR_SPLIT), ft_exit(map), -1);
	rgb = takergb(rgb_str);
	return (rgb);
}
