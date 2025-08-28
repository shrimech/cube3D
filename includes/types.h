/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:35 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/08/28 06:52:35 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
}	t_map;

typedef struct s_point
{
	struct s_point *north;
	struct s_point *west;
	struct s_point *east;
	struct s_point *south;
}	t_point;
