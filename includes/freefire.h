/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 23:02:09 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEFIRE_H
# define FREEFIRE_H

# include "game.h"
# include "get_next_line.h"
# include "libft.h"
# include "parse.h"
# include "types.h"
# include <stdio.h>
# include <unistd.h>

/*---------------***	GB_COL	***------------------*/
void	*my_alloc(size_t size, t_mem_scope scope);
void	collector_init(t_game *game);
void	collector_register(void *ptr, t_mem_scope scope);
void	cleanup_exit(int exit_code, char *error);
void	destroy_game(t_game *game);
void	append_collected(t_collect **head, t_collect **tail,
			t_collect *new_col);
void	delete_collected(t_collect **head, t_collect *prev,
			t_collect **to_delete);
void	parse_hole_map(t_map *map, t_game *game);
#endif
