/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:13 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/29 02:59:16 by shrimech         ###   ########.fr       */
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
		printf("error");
		return ;
	}
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
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
	printf("F  ::  %d, %d, %d\n", map.f[0], map.f[1], map.f[2]);
	printf("C  ::  %d, %d, %d\n", map.c[0], map.c[1], map.c[2]);
}
