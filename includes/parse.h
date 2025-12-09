/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:13 by ehamza            #+#    #+#             */
/*   Updated: 2025/08/28 12:44:09 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "./types.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

char	**read_map(t_map *map, int fd);
void	map_init(t_map *map);
void	parse_hole_map(t_map *map);

//---------------------------- debug ----------------

void	print_hole_map(t_map map);
void	print_map(t_map map);
void	print_texture(t_map map);
void	print_colors(t_map map);

#endif
