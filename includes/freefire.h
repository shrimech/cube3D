/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/21 21:17:20 by elhaiba hamza    ###   ########.fr       */
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

// Error functions
void	set_error(char *error);
void	print_error(void);
void	free_error(void);

// Exit function
void	ft_exit(t_map *map);

/*---------------***	GB_COL	***------------------*/
void	*my_alloc(size_t size, t_mem_scope scope);
void	collector_init(t_game *game);
void	collector_register(void *ptr, t_mem_scope scope);
void	cleanup_exit(int exit_code, char *error);
void	append_collected(t_collect **head, t_collect **tail,
			t_collect *new_col);
void	delete_collected(t_collect **head, t_collect *prev,
			t_collect **to_delete);
void	parse_hole_map(t_map *map, t_game *game);
#endif
