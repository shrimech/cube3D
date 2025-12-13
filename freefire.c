/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:15 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/08/28 06:52:15 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freefire.h"
#include "parse.h"

int	main(void)
{
	t_map	map;
	int		fd;

	fd = open("./maps/map.test.cub", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	map_init(&map);
	map.hole_map = read_map(&map, fd);
	if (!map.hole_map) {
		perror("Failed to read map");
		return (1);
	}
	parse_hole_map(&map);
	print_texture(map);
	print_colors(map);
	print_map(map);

}
