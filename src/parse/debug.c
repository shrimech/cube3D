/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:13 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/21 23:23:22 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"
#include "game.h"

void	print_hole_map(t_map map)
{
	int	i;

	i = 0;
	while (map.file_buffer[i])
	{
		printf("%s", map.file_buffer[i]);
		i++;
	}
}

void	print_map(t_map map, t_camera camera)
{
	int	i;

	i = 0;
	printf("_________________________________________________\n");
	printf("|       HERE IS YOUR MAP         		|\n");
	printf("|   WIDTH: %d   HEIGHT: %d       		|\n", map.width, map.height);
	printf("|   POS_X: %f    POS_Y: %f         |\n", camera.pos_x, camera.pos_y);
	printf("|_______________________________________________|\n");
	if (!map.map)
	{
		return ;
	}
	while (i <= map.width)
	{
		printf("$");
		i++;
	}
	printf("$");
	i = 0;
	while (map.map[i])
	{
		printf("\n$%s$", map.map[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i <= map.width)
	{
		printf("$");
		i++;
	}
	printf("$\n");
}

void	print_texture(t_map map)
{
	printf("___________________________________\n");
	printf("|    HERE IS YOUR MAP ELEMENTS    |\n");
	printf("|_________________________________|\n");
	printf("EA :: %s\n", map.ea ? map.ea : "(null)");
	printf("NO :: %s\n", map.no ? map.no : "(null)");
	printf("SO :: %s\n", map.so ? map.so : "(null)");
	printf("WE :: %s\n", map.we ? map.we : "(null)");
}

void	print_colors(t_map map)
{
	printf("floor:      %d   , ceil:       %d\n", map.f, map.c);
}
