/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:55:37 by ehamza            #+#    #+#             */
/*   Updated: 2025/08/28 12:43:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <freefire.h>

int	check_element(char *first_element)
{
	static int	mask = 0;
	int			bit;

	bit = 0;
	if (strncmp(first_element, "NO ", 3) == 0)
		bit = E_NO;
	else if (strncmp(first_element, "SO ", 3) == 0)
		bit = E_SO;
	else if (strncmp(first_element, "WE ", 3) == 0)
		bit = E_WE;
	else if (strncmp(first_element, "EA ", 3) == 0)
		bit = E_EA;
	else if (strncmp(first_element, "F ", 2) == 0)
		bit = E_F;
	else if (strncmp(first_element, "C ", 2) == 0)
		bit = E_C;
	else
		return (0); // line is not an element
	if (mask & bit)
		return (-1); // duplicate detected
	mask |= bit;     // set the bit
	return (bit);    // return the bit that was set
}

void	parse_elements(void)
{
}

void	parse_map(void)
{
}

void	parse_hole_map(t_map *map)
{

}
