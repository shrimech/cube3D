/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:42:13 by shrimech          #+#    #+#             */
/*   Updated: 2025/08/29 02:59:16 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"

void print_map(t_map map)
{
    int i = 0;
    while (map.map[i])
    {
        printf("%s",map.map[i]);
        i++;
    }
    printf("\n\n");
}


void  print_texture(t_map map)
{
    printf("EA  ::  %s",map.EA);
    printf("NO  ::  %s",map.NO);
    printf("SO  ::  %s",map.SO);
    printf("WE  ::  %s",map.WE);
}

void print_colors(t_map map)
{
    printf("F  :: %s",map.F);
    printf("C  :: %s",map.C);
}




// gcc read_map.c debug.c ../gnl/get_next_line.c ../gnl/get_next_line_utils.c  ../libft/libft.a -g