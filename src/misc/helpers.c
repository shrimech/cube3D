/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:38:43 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 20:38:53 by elhaiba hamza    ###   ########.fr       */
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
