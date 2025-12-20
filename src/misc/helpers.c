/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:38:43 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/20 01:15:37 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	delete_collected(t_collect **head, t_collect *prev,
		t_collect **to_delete)
{
	t_collect	*tmp;

	tmp = *to_delete;
	if (!tmp)
		return ;
	if (!prev)
		*head = tmp->next;
	else
	{
		prev->next = tmp->next;
	}
	*to_delete = tmp->next;
	free(tmp);
}

void	append_collected(t_collect **head, t_collect **tail, t_collect *new_col)
{
	if (!new_col)
		return ;
	if (!*head)
	{
		*head = new_col;
		*tail = new_col;
	}
	else
	{
		(*tail)->next = new_col;
		*tail = new_col;
	}
}
