/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/08/28 10:56:31 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"

void map_init(t_map *map)
{
    map->C = NULL;
    map->EA = NULL;
    map->F = NULL;
    map->map = NULL;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
}

int main()
{
    t_map   map;
    map_init(&map);
}