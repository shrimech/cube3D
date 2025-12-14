/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/14 01:22:42 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEFIRE_H
# define FREEFIRE_H

# include "../src/gnl/get_next_line.h"
# include "../src/libft/libft.h"
# include "./game.h"
# include "./parse.h"
# include "./types.h"

# include <stdio.h>
# include <unistd.h>

// Error functions
void	set_error(char *error);
void	print_error(void);
void	free_error(void);

// Exit function
void	ft_exit(t_map *map);

#endif
