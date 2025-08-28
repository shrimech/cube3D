/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:04 by ehamza            #+#    #+#             */
/*   Updated: 2024/12/08 14:19:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_buffer(int fd);
void	fill_word(int fd, char **word, char **line, char **newline_pos);
void	ft_save(char **reminder, char *buffer);
char	*ft_last(char	*line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_memchr(char *str);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *str);
#endif