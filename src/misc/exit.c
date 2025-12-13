/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 05:47:29 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/13 06:32:29 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>
#include <stdlib.h>
#include <unistd.h>

static void	free_textures(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}

static void	free_hole_map(t_map *map)
{
	int	i;

	if (!map->hole_map)
		return;
	i = 0;
	while (i < map->height)
	{
		if (map->hole_map[i])
			free(map->hole_map[i]);
		i++;
	}
	free(map->hole_map);
}

static void	free_map(t_map *map)
{
	int	i;

	if (!map->map)
		return;
	i = 0;
	while (i < map->height)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	ft_exit(t_map *map)
{
	free_textures(map);
	free_hole_map(map);
	free_map(map);
	print_error();
	free_error();
	exit(1);
}

