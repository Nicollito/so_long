/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:01:43 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/07 10:13:03 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(t_alloc *all, int nbr_call)
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
			print_assets(all, i, j, nbr_call);
			j++;
		}
		i++;
	}
}

void	print_assets(t_alloc *all, int i, int j, int nbr_call)
{
	if(all->dm.map[i][j] == 'C')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->mlx.col, j * 120, i * 120);
	if(all->dm.map[i][j] == 'E')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->mlx.drc, j * 120, i * 120);
	if(all->dm.map[i][j] == 'P')
	{
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->mlx.grd, j * 120, i * 120);
		if (!nbr_call)
		{
			all->dc.x = j * 120;
			all->dc.y = i * 120;
		}
	}
	if(all->dm.map[i][j] == '0')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->mlx.grd, j * 120, i * 120);
	if(all->dm.map[i][j] == '1')
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
				all->mlx.wl, j * 120, i * 120);
}
