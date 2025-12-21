/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:53:17 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/20 01:14:56 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

void	clear_image(t_game *game)
{
	int	total_bytes;

	total_bytes = HEIGHT * game->line_lengh;
	ft_bzero(game->data, total_bytes);
}
