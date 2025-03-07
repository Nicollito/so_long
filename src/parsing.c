/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:08:57 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/07 14:34:05 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	shape_map(t_alloc *all)
{
	int		i;
	ssize_t	len;

	i = all->dm.h - 1;
	len = ft_strlen(all->dm.map[i]);
	while (--i >= 0)
	{
		if (len != ft_strlen_until(all->dm.map[i], '\n') - 1)
		{
			print_error("Error\nInvalid shape of the map.\n");
			exit(free_all(all));
		}
	}
	all->dm.w = len;
}

void	format_name(char *name)
{
	if (!name)
	{
		print_error("Error\nInvalid argument format.\n");
		exit(EXIT_FAILURE);
	}
	name = ft_strrchr(name, '.');
	if (ft_strncmp(name, ".ber", 4))
	{
		print_error("Error\nInvalid argument format.\n");
		exit(EXIT_FAILURE);
	}
}

void	border_map(t_alloc *all)
{
	int	i;

	i = 0;
	while (all->dm.map[0][i] && all->dm.map[0][i] != '\n'
		&& all->dm.map[all->dm.h - 1][i])
	{
		if (all->dm.map[0][i] != '1' || all->dm.map[all->dm.h - 1][i] != '1')
		{
			print_error("Error\nInvalid map border\n");
			exit(free_all(all));
		}
		i++;
	}
	i = 1;
	while (i < all->dm.h - 1)
	{
		if (all->dm.map[i][0] != '1' || all->dm.map[i][all->dm.w -1] != '1')
		{
			print_error("Error\nInvalid map border\n");
			exit(free_all(all));
		}
		i++;
	}
}

void	map_content(t_alloc *all)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (all->dm.map[i])
	{
		j = 0;
		while (all->dm.map[i][j])
		{
			c = all->dm.map[i][j];
			if (c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P' && c != '\n')
			{
				print_error("Error\nUnexpected value in map content.\n");
				exit(free_all(all));
			}
			j++;
		}
		i++;
	}
}

int	verif_char(t_alloc *all, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (all->dm.map[i])
	{
		j = 0;
		while (all->dm.map[i][j])
		{
			if (all->dm.map[i][j] == c)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}
