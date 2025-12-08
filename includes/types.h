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
# define TYPES_H

//---------------*** enums ***------------------//

typedef enum e_tile
{
	WALL = '1',
	EMPTY = '0',
	EAST = 'E',
	SOUTH = 'S',
	WEST = 'W',
	NORTH = 'N',
	SPACE = ' ',
}			t_tile;

typedef enum e_identifier
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}			t_identifier;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	char	**hole_map;
	long	width;
	long	height;
}			t_map;

#endif
