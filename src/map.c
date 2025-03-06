/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:01:43 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 16:34:03 by nimadela         ###   ########.fr       */
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
			if(all->dm.map[i][j] == 'C')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
						all->mlx.col, x, y);
			if(all->dm.map[i][j] == 'E')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
						all->mlx.drc, x, y);
			if(all->dm.map[i][j] == 'P')
			{
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
						all->mlx.ca, x, y);
				all->dc.x = x;
				all->dc.y = y;
			}
			if(all->dm.map[i][j] == '0')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
						all->mlx.grd, x, y);
			if(all->dm.map[i][j] == '1')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
						all->mlx.wl, x, y);
			x += 120;
			j++;
		}
		y += 120;
		i++;
	}
}
