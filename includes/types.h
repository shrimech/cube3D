/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:35 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/08/28 12:27:18 by shrimech         ###   ########.fr       */
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
	NONE,
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
}	t_point;

typedef struct s_map
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *F;
    char *C;
    char **map;
	t_point	**grid;
	long	width;
	long	height;
}	t_map;

#endif
