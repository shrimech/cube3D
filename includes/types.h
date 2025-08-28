/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:35 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/08/28 10:18:45 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
//---------------*** enums ***------------------//
typedef enum e_tile
{
    WALL = '1',
    EMPTY = '0',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W',
    NORTH = 'N',
} t_tile;

typedef enum e_identifier
{
    NO ,
    SO ,
    WE ,
    EA ,
    F ,
    C ,
} t_identifier;


// ---------------*** structs ***----------------//

typedef struct s_map_elements
{
    t_identifier identifire;
    char    *value;
    struct s_map_elements *next;
}   t_map_elements;


typedef struct s_point
{
    t_tile tile;
    struct s_point *south;
	struct s_point *east;
	struct s_point *west;
	struct s_point *north;
}	t_point;

typedef struct s_map
{
}	t_map;


#endif