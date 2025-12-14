/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:35 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/14 01:19:31 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*---------------*** macros ***------------------*/

# define ERR_GNL "get_next_line failed"
# define ERR_SPLIT "ft_split failed"
# define ERR_TEXTURE_LINE "Invalid texture line, expected: NO ./path_to_texture"
# define ERR_ALLOC "memory allocation failed"
# define ERR_MAP_EARLY "map encountered before all elements were loaded"
# define ERR_DUP_ELEMENTS "duplicate elements in map header"
# define ERR_INV_ELEMENT "invalid content before map"
# define ERR_INV_TILE "invalid map tile"
# define ERR_MAP_MISSING "no map section found"
# define ERR_INV_MAP_LINE "invalid line detected inside map section"

# define NO "NO "
# define SO "SO "
# define WE "WE "
# define EA "EA "
# define F "F "
# define C "C "

/*---------------*** enums ***------------------*/
typedef enum e_tile
{
	E_WALL = '1',
	E_EMPTY = '0',
	E_EAST = 'E',
	E_SOUTH = 'S',
	E_WEST = 'W',
	E_NORTH = 'N',
	E_SPACE = ' ',
}			t_tile;

/* 000001
 * 000010
 * 000100
 * 001000
 * 010000
 * 100000
 * 111111
 * */

typedef enum e_identifier
{
	E_NO = 1 << 0,
	E_SO = 1 << 1,
	E_WE = 1 << 2,
	E_EA = 1 << 3,
	E_F = 1 << 4,
	E_C = 1 << 5,
	E_ALL = E_NO | E_SO | E_WE | E_EA | E_F | E_C,
}			t_identifier;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	char	**map;
	char	**hole_map;
	int		width;
	int		height;
}			t_map;




#endif
