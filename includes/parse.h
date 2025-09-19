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
# include <stdlib.h>
# include <stdio.h>


t_map	parse_map_grid(char **raw_chars, long max_with, long height);



//---------------------------- debug ----------------

void print_map(t_map map);
void  print_texture(t_map map);
void print_colors(t_map map);


#endif
