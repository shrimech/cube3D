/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:48 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/09 19:20:52 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "types.h"
#include <freefire.h>

bool	is_map_line(char c)
{
	return (c == E_WALL || c == E_EMPTY || c == E_EAST || c == E_SOUTH
		|| c == E_WEST || c == E_NORTH || c == E_SPACE);
}

bool	is_empty_line(char c)
{
	return (c == '\n' || c == '\0');
}

char *extract_path(char *line)
{
	char **elements;

	elements = ft_split(line, (char)E_SPACE);
	if (!elements)
		return (perror("ERROR SPLIT"), NULL);
	if (elements[1][0] != '\0' && elements[2] == NULL)
		return (ft_strdup(elements[1]));
	return (NULL);
}

int extract_color(char *line)
{
	(void)line;
	return (13132800);
}
