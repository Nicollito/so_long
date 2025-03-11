/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:01:43 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/11 10:36:43 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(t_alloc *all)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < all->dm.h)
	{
		j = 0;
		x = 0;
		while (j < all->dm.w)
		{
			print_assets(all, i, j);
			j++;
		}
		i++;
	}
}

void	print_assets(t_alloc *all, int i, int j)
{
	if (all->dm.map[i][j] == 'C')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.col, j * 120, i * 120);
	if (all->dm.map[i][j] == 'E' && all->dm.nbr_coll)
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.drc, j * 120, i * 120);
	if (all->dm.map[i][j] == 'E' && !all->dm.nbr_coll)
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.dro, j * 120, i * 120);
	if (all->dm.map[i][j] == 'P')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.grd, j * 120, i * 120);
	if (all->dm.map[i][j] == '0')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.grd, j * 120, i * 120);
	if (all->dm.map[i][j] == '1')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
			all->mlx.wl, j * 120, i * 120);
}

void	decrement_coll(t_alloc *all, int map_y, int map_x)
{
	all->dc.steps++;
	ft_printf("Total steps : %d\n", all->dc.steps);
	if (all->dm.map[map_y][map_x] != 'C')
		return ;
	all->dm.nbr_coll--;
	all->dm.map[map_y][map_x] = '0';
}

void	set_coord_character(t_alloc *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->dm.map[y])
	{
		x = 0;
		while (all->dm.map[y][x])
		{
			if (all->dm.map[y][x] == 'P')
			{
				all->dc.y = y * 120;
				all->dc.x = x * 120;
				return ;
			}
			x++;
		}
		y++;
	}
}
