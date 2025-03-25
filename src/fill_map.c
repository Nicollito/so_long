/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:09:52 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/25 10:23:22 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_map(t_alloc *all, char *name)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(name, O_RDONLY);
	nbr_line_map(all, name);
	all->dm.map = malloc(sizeof(char *) * (all->dm.h + 1));
	if (!all->dm.map)
	{
		close(fd);
		exit(free_all(all));
	}
	all->dm.map[all->dm.h] = NULL;
	while (i < all->dm.h)
	{
		all->dm.map[i] = get_next_line(fd);
		if (!all->dm.map[i++])
		{
			close(fd);
			print_error("Error\nAllocation failed.\n");
			exit(free_all(all));
		}
	}
	close(fd);
}

void	nbr_line_map(t_alloc *all, char *name)
{
	int		res;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		print_error("Error\nMap doesn't exist.\n");
		exit(free_all(all));
	}
	res = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		res++;
	}
	close(fd);
	all->dm.h = res;
}
