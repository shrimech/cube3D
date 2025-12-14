/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:26 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 20:49:52 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "types.h"
#include <freefire.h>

static t_game		*g_game = NULL;
static t_collect	*g_head = NULL;
static t_collect	*g_tail = NULL;

void	collector_init(t_game *game)
{
	game = my_alloc(sizeof(t_game), SCOPE_GAME);
	if (!(game))
	{
		perror("malloc:");
		exit(1);
	}
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

void	cleanup_exit(int exit_code)
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
	exit(exit_code);
}

void	collector_register(void *ptr, t_mem_scope scope)
{
	t_collect	*collect;

	collect = malloc(sizeof(t_collect));
	if (!collect)
		cleanup_exit(1);
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
		cleanup_exit(1);
	collector_register(ptr, scope);
	return (ptr);
}
