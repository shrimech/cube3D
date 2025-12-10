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
#include <stdio.h>


void ft_free_split(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}


bool	is_map_line(char c)
{
	return (c == E_WALL || c == E_EMPTY || c == E_SPACE);
}

bool	is_empty_line(char c)
{
	return (c == '\n' || c == '\0');
}


char *extract_path(char *line)
{
    char	**elements;
    char	*path;
	int		count;

	count = 0;
	elements = ft_split(line, ' ');
    if (!elements)
        return (perror("ERROR SPLIT"), NULL);
    while (elements[count])
        count++;
    if (count != 2 || elements[1][0] == '\0')
    {
        ft_free_split(elements);
		printf("ERROR");
        return (NULL);
    }
    path = ft_strdup(elements[1]);
    ft_free_split(elements);
    return path;
}



int *extract_color(char *line)
{
    int *rgb;

	(void)line;
    rgb = malloc(sizeof(int) * 3);
    if (!rgb)
        return (NULL);

    rgb[0] = 200;
    rgb[1] = 100;
    rgb[2] = 0;

    return rgb;
}

