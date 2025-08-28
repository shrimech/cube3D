/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 06:52:10 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/08/28 12:37:31 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/freefire.h"


static int	ft_strlenc(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_split(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_freemem(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = (char **)malloc ((count_split(s, c) + 1) * 8);
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			split[i] = malloc(ft_strlenc(s, c) + 1);
			if (!split[i])
				return (ft_freemem(split, i));
			j = 0;
			while (*s != c && *s)
				split[i][j++] = *s++;
			split[i++][j] = 0;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
void map_init(t_map *map)
{
    map->C = NULL;
    map->EA = NULL;
    map->F = NULL;
    map->map = NULL;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
}

void read_map(t_map *map ,int i,int j)
{
    char *line;
    int fd = open("map.cub" ,O_WRONLY);
    int indx = 0;
    int z = 0;
    
    map->map = malloc((j- i + 1) * sizeof(char *));
    while(line = get_next_line(fd))
    {
        if (indx > i && j - indx >= 0)
        {
            map->map[z] = ft_strdup(line);
            z++;
        }
        indx++;
    }
    map->map[z] = NULL;
    
}

void all_map_elements(int fd,t_map *map)
{
    char *line;
    char **split;
    int i = 0;
    int j = 0;
    
    while(line = get_next_line(fd))
    {
        if (*line == 'N' || *line == 'S' || *line == 'W' || *line == '\n'
            || *line == 'E' || *line == 'F' || *line == 'C')
        {
            split = ft_split(line ,' ');
            if (*line == 'N')
                map->NO = ft_strdup(split[1]);
            if(*line == 'S')
                map->SO = ft_strdup(split[1]);
            if (*line == 'W')
                map->WE = ft_strdup(split[1]);
            if(*line == 'E')
                map->EA = ft_strdup(split[1]);
            if (*line == 'F')
                map->F = ft_strdup(split[1]);
            if(*line == 'C')
                map->C = ft_strdup(split[1]);
            i++;
            j++;
        }
        else
            j++;
    }
    close(fd);
    read_map(map,i,j);
}

int main()
{
    t_map   map;
    int fd = open("map.cub",O_RDONLY);
    map_init(&map);
    all_map_elements(fd,&map);
}