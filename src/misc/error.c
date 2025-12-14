/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 04:13:55 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 01:21:19 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <freefire.h>

static char	*g_error = NULL;

void	set_error(char *error)
{
	g_error = ft_strdup(error);
}

bool	is_there_an_error(void)
{
	if (g_error)
		return (false);
	return (true);
}

void	print_error(void)
{
	if (g_error)
		ft_putendl_fd(g_error, 2);
}

void	free_error(void)
{
	if (g_error)
		free(g_error);
	g_error = NULL;
}
