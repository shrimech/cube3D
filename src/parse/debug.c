/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:13 by shrimech          #+#    #+#             */
/*   Updated: 2025/12/14 01:21:40 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"

void	print_hole_map(t_map map)
{
	int	i;

	i = 0;
	while (map.hole_map[i])
	{
		printf("%s", map.hole_map[i]);
		i++;
	}
}

void	print_map(t_map map)
{
	int	i;

	i = 0;
	printf("___________________________________\n");
	printf("|       HERE IS YOUR MAP           |\n");
	printf("|   WIDTH: %d   HEIGHT: %d         |\n", map.width, map.height);
	printf("___________________________________\n");
	if (!map.map)
	{
		return ;
	}
	while (map.map[i])
	{
		printf("$%s$\n", map.map[i]);
		i++;
	}
}

void	print_texture(t_map map)
{
	printf("___________________________________\n");
	printf("|    HERE IS YOUR MAP ELEMENTS    |\n");
	printf("___________________________________\n");
	printf("EA :: %s", map.ea ? map.ea : "(null)");
	printf("NO :: %s", map.no ? map.no : "(null)");
	printf("SO :: %s", map.so ? map.so : "(null)");
	printf("WE :: %s", map.we ? map.we : "(null)");
}

void	print_colors(t_map map)
{
	printf("floor:      %d   , ceil:       %d\n", map.f, map.c);
}
