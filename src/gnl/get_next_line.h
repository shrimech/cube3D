/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:04 by ehamza            #+#    #+#             */
/*   Updated: 2025/12/09 19:22:25 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_buffer(int fd);
void	fill_word(int fd, char **word, char **line, char **newline_pos);
void	ft_save(char **reminder, char *buffer);
char	*ft_last(char *line);
char	*ft_str_join(char *s1, char *s2);
char	*ft_mem_chr(char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
#endif
