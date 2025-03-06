/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:17:53 by nimadela          #+#    #+#             */
/*   Updated: 2025/02/19 10:01:51 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*fill_line(int fd, char *stash)
{
	ssize_t	b_read;
	char	*res;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(stash) + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy_until(tmp, stash, '\0');
	b_read = 1;
	while (b_read && !check_line(stash))
	{
		b_read = read(fd, stash, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(tmp);
			return (ft_bzero(stash, ft_strlen(stash)), NULL);
		}
		stash[b_read] = '\0';
		res = ft_strjoin_gnl(tmp, stash);
		free(tmp);
		if (!res)
			return (NULL);
		tmp = res;
	}
	return (res);
}

char	*fill_stash(char *buffer, char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while (buffer[i])
	{
		stash[j] = buffer[i];
		j++;
		i++;
	}
	stash[j] = '\0';
	free(buffer);
	return (stash);
}

char	*get_my_line(char *line, char *buffer, char *stash)
{
	ft_strcpy_until(line, buffer, '\n');
	fill_stash(buffer, stash);
	if (!ft_strlen(line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_line(stash[fd]))
	{
		buffer = malloc(sizeof(char) * ft_strlen(stash[fd]) + 1);
		if (!buffer)
			return (NULL);
		ft_strcpy_until(buffer, stash[fd], '\0');
	}
	else
		buffer = fill_line(fd, stash[fd]);
	if (!buffer)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen_until(buffer, '\n') + 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	line = get_my_line(line, buffer, stash[fd]);
	return (line);
}
