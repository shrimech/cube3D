/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:13 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/14 01:20:42 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "types.h"
# include <stdbool.h>

/*---------------------------- Parsers ----------------*/
char	**read_map(t_map *map, int fd);
void	map_init(t_map *map);
void	parse_hole_map(t_map *map);
void	map_width(t_map *map, int mapline);
void	set_error(char *error);
void	print_error(void);
bool	is_there_an_error(void);

/*---------------------------- Checkers ----------------*/
bool	is_empty_line(char c);
bool	is_map_line(char c);

//---------------------------- Extractors ----------------
char	*extract_path(t_map *map, char *line);
int		*extract_color(t_map *map, char *element);

//---------------------------- Eebug ----------------
void	print_hole_map(t_map map);
void	print_map(t_map map);
void	print_texture(t_map map);
void	print_colors(t_map map);

#endif
