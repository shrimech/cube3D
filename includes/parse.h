/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:13 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/21 21:33:36 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "types.h"
# include <stdbool.h>
# include <stddef.h>

/*---------------------------- Parsers ----------------*/
char	**read_map(t_map *map, int fd);
t_map	*map_init(void);
void	parse_map(t_map *map, int map_line);
void	map_width(t_map *map, int mapline);
void	set_error(char *error);
void	print_error(void);
bool	is_there_an_error(void);
void	overwrite_spaces(t_map *map, int map_line);

/*---------------------------- Builders ----------------*/
void	fill_map_element(t_map *map, char *line, int element);

/*---------------------------- Checkers ----------------*/
bool	is_empty_line(char c);
bool	is_map_line(char c);
bool	is_player(char c);
void	map_border(t_map *map);
void	check_start_end(t_map *map);
bool	check_for_an_space(t_map *map, int i, int j);

//---------------------------- Extractors ----------------
char	*extract_path(t_map *map, char *line);
int		extract_color(t_map *map, char *element);

//---------------------------- Helpers ----------------
void	*ft_salloc(size_t nmemb, size_t size);

//---------------------------- Eebug ----------------
void	print_hole_map(t_map map);
void	print_texture(t_map map);
void	print_colors(t_map map);

#endif
