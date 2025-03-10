/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:45 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/10 16:42:55 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	size_map(t_alloc *all)
{
	if (all->dm.h > 17 || all->dm.w > 32)
	{
		print_error("Error\nInvalid map size.\n");
		exit(free_all(all));
	}
}

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
