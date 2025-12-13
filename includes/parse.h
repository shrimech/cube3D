/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:13 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/13 04:55:32 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "./types.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/*---------------------------- debug ----------------*/
char	**read_map(t_map *map, int fd);
void	map_init(t_map *map);
void	parse_hole_map(t_map *map);
void	map_width(t_map *map, int mapline);
void	set_error(char *error);

/*---------------------------- debug ----------------*/
bool	is_empty_line(char c);
bool	is_map_line(char c);

//---------------------------- debug ----------------
char	*extract_path(char *line);
int		*extract_color(char *line);

//---------------------------- debug ----------------
void	print_hole_map(t_map map);
void	print_map(t_map map);
void	print_texture(t_map map);
void	print_colors(t_map map);

#endif
