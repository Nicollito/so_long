/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:43 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/24 09:51:14 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

#include "../include/tmp.h"

char	*ft_strcpy_until(char *dest, char *src, char delim);
char	*get_next_line(int fd);
char	*fill_line(int fd, char *line);
char	*check_stash(char *stash);
int		check_line(char *s);
ssize_t	ft_strlen_until(char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	*get_my_line(char *line, char *buffer, char *stash);

#endif