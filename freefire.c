/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:15 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/08/28 06:52:15 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	main(void)
{
	t_map	map;
	int		fd;

	fd = open("map.cub", O_RDONLY);
	map_init(&map);
	map.hole_map = read_map(&map, fd);
	print_hole_map(map);
}
