/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:22:31 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/11 10:41:25 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_alloc *all, char **map, int x, int y)
{
	if (y >= all->dm.h || x >= all->dm.w)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E'
			|| map[y][x] == 'P')
	{
		map[y][x] = 'K';
		flood_fill(all, map, x + 1, y);
		flood_fill(all, map, x - 1, y);
		flood_fill(all, map, x, y + 1);
		flood_fill(all, map, x, y - 1);
	}
}

void	check_flood_fill(char **map, t_alloc *all)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
			{
				print_error(
					"Error\nUnplayable map: inaccessible areas detected.\n");
				free_map(map);
				exit(free_all(all));
			}
			x++;
		}
		y++;
	}
}

void	set_flood_fill(t_alloc *all)
{
	char	**cpy_map;

	cpy_map = copy_map(all);
	flood_fill(all, cpy_map, all->dc.x / 120, all->dc.y / 120);
	check_flood_fill(cpy_map, all);
	free_map(cpy_map);
}
