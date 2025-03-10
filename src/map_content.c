/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:08:57 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/10 17:16:13 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

char	**copy_map(t_alloc *all)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (all->dm.h + 1));
	if (!res)
		exit(free_all(all));
	res[all->dm.h] = NULL;
	while (i < all->dm.h)
	{
		res[i] = ft_strdup(all->dm.map[i]);
		if (!res[i])
		{
			free_map(res);
			exit(free_all(all));
		}
		i++;
	}
	return (res);
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
