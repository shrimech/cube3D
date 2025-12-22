/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:48 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/22 08:40:08 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <freefire.h>

bool	is_map_line(char c)
{
	return (c == E_WALL || c == E_EMPTY || c == E_SPACE);
}

bool	is_empty_line(char c)
{
	return (c == '\n' || c == '\0');
}

char	*extract_path(char *line)
{
	char	**elements;
	char	*path;
	int		count;

	count = 0;
	elements = ft_split(line, ' ');
	if (!elements)
		cleanup_exit(1, ERR_SPLIT);
	collector_register(elements, SCOPE_PARSE);
	while (elements[count])
	{
		collector_register(elements[count], SCOPE_PARSE);
		count++;
	}
	if (count != 2 || elements[1][0] == '\0')
	{
		cleanup_exit(1, ERR_TEXTURE_LINE);
	}
	path = ft_strdup(elements[1]);
	path[ft_strlen(path) - 1] = '\0';
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
			cleanup_exit(1, ERR_RGB);
		rgb |= (value << (16 - 8 * i));
		i++;
	}
	return (rgb);
}

int	extract_color(char *element)
{
	char	**rgb_str;
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
	if (count != 2)
		cleanup_exit(1, ERR_RGB_CONTENT);
	rgb_str = ft_split(element, ',');
	if (!rgb_str)
		cleanup_exit(1, ERR_SPLIT);
	collector_register(rgb_str, SCOPE_PARSE);
	i = 0;
	while (rgb_str[i])
		collector_register(rgb_str[i++], SCOPE_PARSE);
	if (!rgb_str[0] || !rgb_str[1] || !rgb_str[2] || rgb_str[2][0] == '\n')
		cleanup_exit(1, ERR_SPLIT);
	return (takergb(rgb_str));
}
