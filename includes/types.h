/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:35 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 23:36:37 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*---------------*** macros ***------------------*/

# define ERR_GNL "Get_next_line failed"
# define ERR_SPLIT "Ft_split failed"
# define ERR_TEXTURE_LINE "Invalid texture line, expected: XX XXXXXXX"
# define ERR_ALLOC "Memory allocation failed"
# define ERR_MAP_EARLY "Map encountered before all elements were loaded"
# define ERR_DUP_ELEMENTS "Duplicate elements in map header"
# define ERR_INV_ELEMENT "Invalid content before map"
# define ERR_INV_TILE "Invalid map tile"
# define ERR_MAP_MISSING "No map section found"
# define ERR_INV_MAP_LINE "Invalid line detected inside map section"
# define ERR_MANY_PLAYERS "Multiple player spawn points detected."
# define ERR_NO_PLAYER "No player spawn point found."
# define ERR_MAP_OPEN "Map must be surrounded by walls."
# define ERR_RGB "RGB value out of range."
# define ERR_RGB_CONTENT "Invalid RGB format (expected R,G,B)."
# define ERR_OPEN "Could not open file."

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
	char	**file_buffer;
	int		width;
	int		height;
}			t_map;

typedef enum e_scope
{
	SCOPE_PARSE,
	SCOPE_GAME,
}						t_mem_scope;

typedef struct s_collect
{
	void				*ptr;
	t_mem_scope			scope;
	struct s_collect	*next;
}						t_collect;

#endif
