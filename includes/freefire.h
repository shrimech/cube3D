/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:19 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/13 06:49:09 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEFIRE_H
#define FREEFIRE_H

#include "../src/gnl/get_next_line.h"
#include "../src/libft/libft.h"
#include "./types.h"
#include "./parse.h"
#include <stdio.h>
#include <unistd.h>

// Error functions
void	set_error(char *error);
void	print_error();
void	free_error();

// Exit function
void	ft_exit(t_map *map);

#endif
