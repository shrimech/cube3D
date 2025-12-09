/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:28 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/09 19:23:06 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*dup;
// 	int		i;
//
// 	i = 0;
// 	dup = malloc(ft_strlen(s) + 1);
// 	if (!dup)
// 		return (0);
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

char	*ft_mem_chr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 10)
			return ((str + i));
		i++;
	}
	return (NULL);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL)
		s2 = ft_strdup("");
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (free(s1), free(s2), join);
}
