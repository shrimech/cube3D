/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:26 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/21 21:19:27 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "types.h"
#include <freefire.h>

static t_game		*g_game = NULL;
static t_collect	*g_head = NULL;
static t_collect	*g_tail = NULL;

void	collector_init(t_game *game)
{
	game = my_alloc(sizeof(t_game), SCOPE_GAME);
	g_game = game;
}

void	collector_cleanup(t_mem_scope scope)
{
	t_collect	*prev;
	t_collect	*curr;
	t_collect	*next;

	prev = NULL;
	curr = g_head;
	while (curr)
	{
		next = curr->next;
		if (curr->scope == scope)
		{
			free(curr->ptr);
			if (curr == g_tail)
				g_tail = prev;
			delete_collected(&g_head, prev, &curr);
			curr = next;
		}
		else
		{
			prev = curr;
			curr = next;
		}
	}
}

void	cleanup_exit(int exit_code, char *error)
{
	t_collect	*curr;
	t_collect	*next;

	collector_cleanup(SCOPE_PARSE);
	collector_cleanup(SCOPE_GAME);
	curr = g_head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	ft_putstr_fd(error, 2);
	exit(exit_code);
}

void	collector_register(void *ptr, t_mem_scope scope)
{
	t_collect	*collect;

	collect = malloc(sizeof(t_collect));
	if (!collect)
		cleanup_exit(1, ERR_ALLOC);
	collect->ptr = ptr;
	collect->scope = scope;
	collect->next = NULL;
	append_collected(&g_head, &g_tail, collect);
}

void	*my_alloc(size_t size, t_mem_scope scope)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		cleanup_exit(1, ERR_ALLOC);
	collector_register(ptr, scope);
	return (ptr);
}
