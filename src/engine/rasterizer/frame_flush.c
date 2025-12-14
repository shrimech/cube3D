/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:53:17 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 05:53:47 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	clear_image(t_game *game)
{
	int	total_bytes;

	total_bytes = HEIGHT * game->line_lengh;
	ft_bzero(game->data, total_bytes);
}
